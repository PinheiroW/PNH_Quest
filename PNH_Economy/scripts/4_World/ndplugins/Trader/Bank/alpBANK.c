class alpBANK 
{
	// [DEBUG] Ative ou desative os logs de transação aqui
	static const bool DEBUG_BANK = true;

	static void BankLog(string msg)
	{
		if (DEBUG_BANK) Print("[PNH_BANK_DEBUG] " + msg);
	}

	static ref alpBankAccount alp_ClientAccount;
	static ref map<int,PlayerBase> alp_Debtors = new map<int,PlayerBase>;
	static ref map<int,int> alp_BankBalance;
	static ref map<int,int> alp_PlayerBankBalance;
	static ref map<int,int> alp_TraderBankBalance = new map<int,int>; 
	static ref map<int,ref alpBankAccount> alp_AccountsMapped = new map<int,ref alpBankAccount>;
	static ref alpCurrencies alp_Currencies = new alpCurrencies();

	static bool m_GlobalBalanceNeedsSave = false;
	static bool m_PlayerBalanceNeedsSave = false;
	
	static float GetCurrencyRate(int currency) { return alp_Currencies.GetCurrencyRate( currency );	}
	
	static void Exchange(int accountid, int fromCurrency, int toCurrency, int fromAmmount, int toAmmount,  PlayerBase player )
	{
		BankLog("Exchange -> AccID: " + accountid + " | From: " + fromAmmount + " to " + toAmmount);
		int back = AddBalanceToAccount( accountid, fromCurrency, -fromAmmount, player );
		
		if (!back)
		{
			AddBankBalance(fromCurrency, fromAmmount );
			AddBankBalance(toCurrency, -toAmmount );
			AddBalanceToAccount( accountid, toCurrency, toAmmount, player );
		}
		else
		{
			back = fromAmmount - back;
			AddBalanceToAccount( accountid, fromCurrency, back, player );
		}
	}
	
	static void AddExtraLoanFee(int accountid, int currency, int cost )
	{
		alpBankAccount account = GetBankAccount(accountid);		
		if ( account )
		{
			alpLoans loan = account.GetLoan(currency );
			if ( loan ) loan.Interest = loan.Interest + cost;		
			account.Save();
		} 
	} 
	
	static  void PartialLoanRepayment(int accountid, int currency, int pay,  PlayerBase player )
	{
		alpBankAccount account = alpBANK.GetBankAccount(accountid);		
		if ( account )
		{
			alpLoans loan = account.GetLoan(currency );
			if ( loan )
			{
				int total = loan.Principal + loan.Interest;
				total -= pay;
				
				if ( total == 0 || total < 0 )
				{
					AddBankBalance( currency, loan.Interest );					
					account.RemoveLoanRecord( loan );
					AddBalanceToAccount( accountid, currency, -pay, player );
					
					PlayerBase p;
					if ( alp_Debtors.Find( accountid, p ) )
					{
						if ( p ) CheckDebts(p,account);
					}					
				}
				else
				{
					total = loan.Interest - pay;
					if ( total < 0 )
					{
						AddBankBalance( currency, loan.Interest );	
						loan.Interest = 0;
						loan.Principal = loan.Principal + total;
					}
					else
					{
						AddBankBalance( currency, pay );	
						loan.Interest = loan.Interest - pay;				
					}
					AddBalanceToAccount( accountid, currency, -pay, player );
				}
			}		
		}
	}
	
	static void TakeLoan( PlayerBase player, Param6<int,int,int,int,float,int> takeLoan)
	{
		alpLoans loan = new alpLoans(takeLoan);
		alpBankAccount account = alpBANK.GetBankAccount(takeLoan.param1);			
		account.AddLoan( loan );
		AddBalanceToAccount( takeLoan.param1, takeLoan.param2, takeLoan.param3, player );
		BankLog("TakeLoan -> Player " + takeLoan.param1 + " took loan of " + takeLoan.param3);
	}		
	
	static void TakeBusinessProfit( int currency, int ammount , bool full = false)
	{
		float rate = GetND().GetMS().GetOptoinsTrader().BankProfit;
		if ( full ) rate = 1;
		ammount = ammount * rate;
		AddBankBalance( currency, ammount);
	}

	static float GetExchangeRate(int from, int to )
	{
		int balanceFrom = GetBankBalance( from);
		int balanceTo = GetBankBalance( to);
		alpCurrency currencyFrom = alp_Currencies.GetCurrency( from );
		alpCurrency currencyTo = alp_Currencies.GetCurrency( to );
		float rateFrom = currencyFrom.GetRate();
		float rateTo = currencyTo.GetRate();
		float offset = currencyTo.GetOffset();
		float total = ( balanceFrom / rateFrom + balanceTo / rateTo ) + 0.001; 
		float rate =  ( balanceTo / rateTo ) / total;
		rate = ( rate - 0.5 ) / -0.5;
		rate =  offset * rate * (rateFrom / rateTo);
		float finalRate = ( rateFrom / rateTo ) + rate;
		return finalRate;
	}
	
	static int GetExchangeLimit(int currency) { return alp_BankBalance.Get(currency); }	
	static int GetBankLoanLimit(int currency) { return GetBankCapital(currency) * GetND().GetMS().GetOptoinsTrader().BankLoanLimitPerAssets; }
	
	static int GetBankCapital(int currency)
	{
		int total, balance;
		balance = alp_PlayerBankBalance.Get(currency);
		total += balance;
		balance = alp_TraderBankBalance.Get(currency);
		total += balance;
		return total;	
	}

	static int GetBankBalance(int currency) { return alp_BankBalance.Get(currency); }	

	static void InitServerSide()
	{
		alpCurrencies currencies;
		int i,curency;
		JsonFileLoader< map<int,int>>.JsonLoadFile(ALP_MISSIONS_BANK_P_BALANCE, alp_PlayerBankBalance );	
		if (!alp_PlayerBankBalance)
		{
			alp_PlayerBankBalance = new map<int,int>;
			currencies = GetCurencies();
			for ( i = 0;i < currencies.alp_Currencies.Count();i++)
			{
				curency = currencies.alp_Currencies.GetKey(i);			
				alp_PlayerBankBalance.Set( curency, 0 );
			}	
			JsonFileLoader< map<int,int>>.JsonSaveFile(ALP_MISSIONS_BANK_P_BALANCE, alp_PlayerBankBalance );		
		}	

		JsonFileLoader< map<int,int>>.JsonLoadFile(ALP_MISSIONS_BANK_BALANCE, alp_BankBalance );	
		if (!alp_BankBalance)
		{
			alp_BankBalance = new map<int,int>;
			currencies = GetCurencies();
			for (i = 0;i < currencies.alp_Currencies.Count();i++)
			{
				curency = currencies.alp_Currencies.GetKey(i);			
				alp_BankBalance.Set( curency, 0 );
			}	
			JsonFileLoader< map<int,int>>.JsonSaveFile(ALP_MISSIONS_BANK_BALANCE, alp_BankBalance );		
		}		

		if (GetGame().IsServer())
		{
			BankLog("InitServerSide -> Iniciando CallQueue de Gravacao (60s)");
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(alpBANK.AsyncBankSaveQueue, 60000, true);
		}
	}

	static void AsyncBankSaveQueue()
	{
		if (!GetGame().IsServer()) return;

		bool hasSaved = false;

		if (m_GlobalBalanceNeedsSave)
		{
			JsonFileLoader< map<int,int> >.JsonSaveFile(ALP_MISSIONS_BANK_BALANCE, alp_BankBalance);
			m_GlobalBalanceNeedsSave = false;
			hasSaved = true;
			BankLog("AsyncBankSaveQueue -> Global Bank Balance guardado no disco.");
		}

		if (m_PlayerBalanceNeedsSave)
		{
			JsonFileLoader< map<int,int> >.JsonSaveFile(ALP_MISSIONS_BANK_P_BALANCE, alp_PlayerBankBalance);
			m_PlayerBalanceNeedsSave = false;
			hasSaved = true;
			BankLog("AsyncBankSaveQueue -> Global Player Balance guardado no disco.");
		}

		if (alp_AccountsMapped)
		{
			for (int i = 0; i < alp_AccountsMapped.Count(); i++)
			{
				alpBankAccount acc = alp_AccountsMapped.GetElement(i);
				if (acc && acc.m_NeedsSave)
				{
					string path = ALP_MISSIONS_BANK_FOLDER + acc.PlayerID + ".json";
					JsonFileLoader< alpBankAccount>.JsonSaveFile(path, acc);
					acc.m_NeedsSave = false;
					hasSaved = true;
					BankLog("AsyncBankSaveQueue -> Conta Pessoal guardada no disco [ID: " + acc.PlayerID + "]");
				}
			}
		}

		if (!hasSaved && DEBUG_BANK)
		{
			// Opcional: Mostra que o loop passou, mas não havia nada para gravar (comente se for muito spam)
			// BankLog("AsyncBankSaveQueue -> Verificado. Nenhuma alteracao pendente.");
		}
	}

	static void AddBankBalance(int currency, int ammount)
	{
		int balance, max;
		if ( alp_BankBalance.Find( currency, balance ) )
		{				
			max =  int.MAX - Math.AbsInt(ammount);
			if ( balance < max ) balance += ammount;				
			if ( balance < 0 ) balance = 0;						
		}
		alp_BankBalance.Set( currency, balance);		
		m_GlobalBalanceNeedsSave = true;
	}	

	static void AddBankCapital(int currency, int ammount, bool player = true )
	{
		int balance, max;
		if ( player )
		{
			if ( alp_PlayerBankBalance.Find( currency, balance ) )
			{				
				max =  int.MAX - Math.AbsInt(ammount);
				if ( balance < max ) balance += ammount;								
			}
			alp_PlayerBankBalance.Set( currency, balance);		
			m_PlayerBalanceNeedsSave = true;
		}
		else
		{
			if ( alp_TraderBankBalance.Find( currency, balance ) )
			{				
				max =  int.MAX - Math.AbsInt(ammount);
				if ( balance < max )
				{
					balance += ammount;	
					if ( balance < 0) balance = 0;					
				}								
			}
			alp_TraderBankBalance.Set( currency, balance);	
		}
	}
	
	static int GetDepositLimit(PlayerBase player) { return GetND().GetMS().GetOptoinsTrader().PlayerDepositLimit; }
	static float GetLoanInterest(PlayerBase player) { return GetND().GetMS().GetOptoinsTrader().BankLoanInterestPerDay; }
	
	static int GetLoanLimit(PlayerBase player, int currencyID)
	{
		int playerlimit = GetND().GetMS().GetOptoinsTrader().PlayerLoanLimit;
		return Math.Min( playerlimit , GetBankLoanLimit( currencyID ) );	
	}	

	static void SetClientAccount(alpBankAccount account) { alp_ClientAccount = account; }
	static alpBankAccount GetClientAccount() { return alp_ClientAccount; }

	static int RegisterCard( int playerID, int cardID)
	{
		alpBankAccount account = GetBankAccount( playerID );
		if (account)
		{
			account.AddCard(cardID);
			return true;
		}
		return false;
	}
	
	static void SetBankAccountOnConnect(PlayerBase player, int pID = -1)
	{
		int playerID;
		if ( pID > 0 ) playerID = pID;
		else playerID = player.GetPlayerHive().GetPlayerID();

		string guid = player.GetIdentity().GetPlainId();
		alpBankAccount account; 
		
		if (!alp_AccountsMapped.Find(playerID, account))
		{
			string path = ALP_MISSIONS_BANK_FOLDER + playerID + ".json";
			JsonFileLoader< alpBankAccount>.JsonLoadFile(path, account );	
			if (!account)
			{
				string name = player.GetIdentity().GetName();
				account = new alpBankAccount(playerID,guid,name);
				JsonFileLoader< alpBankAccount>.JsonSaveFile(path, account );	
			}	
			alp_AccountsMapped.Set(playerID,account);
			BankLog("SetBankAccountOnConnect -> Conta carregada para " + name + " [ID: " + playerID + "]");
		}
		CheckDebts(player,account);
	}
	
	static void CheckDebts( PlayerBase player, alpBankAccount account)
	{
		if ( account )
		{
			if ( IsDebtor( account.Loans , account.PlayerID , player) )
			{
				alp_Debtors.Set( player.GetPlayerHive().GetPlayerID() , player );
				player.GetRP().SetDebtor( true );
			}
			else
			{
				PlayerBase p;
				if ( alp_Debtors.Find( account.PlayerID , p ) ) player.GetRP().SetDebtor( false );
			}			
		}	
	}
	
	static bool IsDebtor( array<autoptr alpLoans> loans , int accountID, PlayerBase player)
	{
		if ( loans && loans.Count() > 0 )
		{
			int year,month, day, today;
			GetYearMonthDayUTC(year, month, day);
			today = year + month * 30 + day;
			for ( int i = 0; i < loans.Count() ; )
			{
				alpLoans loan = loans.Get(i);
				int terminated = loan.Terminated[0] + loan.Terminated[1] * 30 + loan.Terminated[2];
				
				if ( terminated < today )
				{
					int currency = loan.CurrencyID;
					int availableCash = GetBalanceInCurrency( accountID,currency );
					int debt = loan.Principal + loan.Interest;
					if ( availableCash > debt )
					{
						AddBankBalance( currency , loan.Interest ); 
						loans.Remove(i);						
						AddBalanceToAccount( accountID,  currency , -debt, player );						
						continue;
					}
					else
					{
						player.GetRP().SetDebt( currency, debt );
						return true;
					}
				}
				i++;
			}			
		}	
		return false;
	}
	
	static int GetBalanceInCurrency(int name, int currency)
	{	
		alpBankAccount account;		
		if (alp_AccountsMapped.Find(name, account)) return account.GetBalance(currency);
		return 0;
	}

	static int AddBalanceToAccount(int name, int currency, int balance, PlayerBase player)
	{
		BankLog("Transacao -> AccID: " + name + " | Moeda: " + currency + " | Valor: " + balance);
		
		int toBankBalance = balance;
		int back = Math.AbsInt(balance);

		alpBankAccount account;		
		if (alp_AccountsMapped.Find(name, account))
		{
			back = account.AddBalance( currency, balance, player);
		}			
		
		toBankBalance -= back;
		AddBankCapital( currency, toBankBalance );	
		return back;	
	}
	
	static void SaveAccount(int name)
	{
		alpBankAccount account;		
		if (alp_AccountsMapped.Find(name, account)) account.Save();	
	}
		
	static bool VerifyBankNote(int currencyID, string type)
	{
		map<int,ref alpBankNote> banknotes = GetCurencies().GetBankNotes(currencyID);
		if (banknotes)
		{
			foreach ( alpBankNote bn : banknotes )
			{
				if ( bn.Name == type ) return true;
			}
		}
		return false;
	}

	static map<int,ref alpBankNote> GetBankNotes(int currencyID) { return GetCurencies().GetBankNotes(currencyID); }	
	
	static alpBankAccount GetBankAccount(int playerID)
	{
		alpBankAccount account; 
		if (alp_AccountsMapped.Find(playerID, account)) return account;
		else
		{
			string path = ALP_MISSIONS_BANK_FOLDER + playerID + ".json";
			JsonFileLoader< alpBankAccount>.JsonLoadFile(path, account );	
			if ( account ) alp_AccountsMapped.Set(playerID, account);
			return account;		
		}
	}
	
	static void BlockCard(int idaccount, int idcard)
	{
		alpBankAccount account = alp_AccountsMapped.Get(idaccount); 
		if (account) account.RemoveCard( idcard );
	}

	static alpCurrencies GetCurencies() { return alp_Currencies; }
}

class alpLoans 
{
	int CurrencyID;
	int Start[3];
	int Terminated[3];
	int Principal;
	int Interest;
	float InterestRate;
	
	void alpLoans(Param6<int,int,int,int,float,int> takeLoan)
	{
		CurrencyID = takeLoan.param2;
		Principal = takeLoan.param3;
		Interest = takeLoan.param4; 
		InterestRate = takeLoan.param5; 
		
		int length = takeLoan.param6;	
		int yearStart,yearEnd,monthStart,monthEnd,dayStart,dayEnd;
		
		GetYearMonthDayUTC( yearStart, monthStart, dayStart );
		Start[0] = yearStart;
		Start[1] = monthStart;
		Start[2] = dayStart;
		
		int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
		dayEnd = dayStart + length;
		int nextMonth;

		if ( GetNextMonth( nextMonth ) && dayEnd >  months[monthStart] )
		{
			yearEnd = yearStart + 1;
			monthEnd = nextMonth;
			dayEnd = dayEnd - months[monthStart];
		}
		else
		{
			if ( dayEnd >  months[monthStart] )
			{
				monthEnd = nextMonth;
				dayEnd = dayEnd - months[monthStart];
			}
			else
			{
				monthEnd = monthStart;
			}
			yearEnd = yearStart;
		}
		Terminated[0] = yearEnd;
		Terminated[1] = monthEnd;		
		Terminated[2] = dayEnd;
	}	
	
	bool GetNextMonth(out int month)
	{
		if ( month < 12 )
		{
			month++;
			return false;
		}
		month = 1;
		return true;
	}
}

class alpBankAccount 
{
	int PlayerID; 
	string GUID; 
	string Name;
	ref array<ref alpLoans> Loans;
	ref array<int> RegisteredCards;
	ref map<int, int> Currencies;
	
	[NonSerialized()]
	bool m_NeedsSave = false;
			
	void alpBankAccount(int playerid, string id, string name)
	{
		PlayerID = playerid;
		GUID = id;
		Name = name;
		RegisteredCards = new array<int>;
		Currencies = new  map<int, int>;
		Loans = new array<ref alpLoans>;
		
		alpCurrencies currencies = alpBANK.GetCurencies();
		for (int i = 0;i < currencies.alp_Currencies.Count();i++)
		{
			int curency = currencies.alp_Currencies.GetKey(i);
			Currencies.Set( curency, 0 );
		}						
	}

	void AddLoan(alpLoans loan)
	{
		if (!Loans) Loans = new array<ref alpLoans>;
		Loans.Insert( loan );	
		Save();
	}
	
	void RemoveLoanRecord( alpLoans loan )
	{
		Loans.RemoveItem( loan );
		Save();
	}
	
	alpLoans GetLoan(int currency)
	{
		if ( Loans )
		{
			for (int i = 0; i < Loans.Count();i++)
			{
				alpLoans loan = Loans.Get(i);
				if ( loan.CurrencyID == currency ) return loan;
			}
		}
		return null;
	}
	
	int GetAccountID() { return PlayerID; }
	bool TakeLoan(int loan, float rate, int length ) { return true; }	
	int GetLoanLimit(int currency) { return 50000; }
	
	void AddCard(int id )
	{	
		RegisteredCards.Insert( id );
		Save();
	}
	
	void RemoveCard(int id)
	{
		RegisteredCards.RemoveItem( id );
		Save();
	}
	
	string GetID() { return GUID; }	
	string GetName() { return Name; }	

	int GetBalance(int currency = 0)
	{
		int balance;
		if ( Currencies.Find( currency, balance)) return balance;
		else
		{
			Currencies.Set(currency,0);
			Save();
			return 0;
		}
	}
	
	int AddBalance( int currency, int change, PlayerBase player)
	{
		int back = Math.AbsInt( change);
		int balance = GetBalance( currency );
		int max =  int.MAX - Math.AbsInt(change);

		if (  ( change < 0 ) ||  ( balance < max ) )
		{
			balance += change;
			
			if ( balance < 0 )
			{
				back = Math.AbsInt( balance );
				Currencies.Set(currency,0);
			}
			else
			{
				if ( balance <= alpBANK.GetDepositLimit(player) )
				{
					back = 0;
					Currencies.Set(currency,balance);				
				}
				else
				{
					back = alpBANK.GetDepositLimit(player) - balance;
					Currencies.Set(currency,alpBANK.GetDepositLimit(player));
				}
			}
			Save();
		}
						
		return back;
	}
	
	void Save()
	{
		if (GetGame().IsServer() )
		{
			m_NeedsSave = true;
			alpBANK.BankLog("Conta marcada para gravacao futura [ID: " + PlayerID + "]");
		}					
	}
}

class alpBankNote 
{
	string Name;
	int Quantity;
	void alpBankNote(string type,int quantity)
	{
		Name = type;
		Quantity = quantity;
	}
}

class alpCurrencies 
{
	ref map<int, ref alpCurrency> alp_Currencies;
	ref map<int, ref map<int,ref alpBankNote>> alp_BankNotes;
	
	void alpCurrencies()
	{	
		alp_Currencies = new map<int, ref alpCurrency>;
		alp_BankNotes  = new map<int, ref map<int,ref alpBankNote>>;
		Init();
	}
	
	map<int,ref alpBankNote> GetBankNotes( int currencyID ) { return alp_BankNotes.Get(currencyID); }
	
	void Init()
	{
		string path = "CfgTraders hideCurrency";
		array<int> disabledCurrencies = new array<int>;
		GetGame().ConfigGetIntArray( path, disabledCurrencies );
		
		int id = 0;		
		if ( disabledCurrencies.Find( 0 ) < 0 ){
			SetCZEcurrency( id,1,0.5 );
			id++;
		}		
		if ( disabledCurrencies.Find( 1 ) < 0 ){
			SetUScurrency( id, 0.05,0.5 );
			id++;
		}		
	}	
	
	private void SetCZEcurrency( int id , float rate, float range) {
		alp_Currencies.Set(id, new alpCurrency(id,"#STR_koruny_name",rate,range));
		map<int,ref alpBankNote> bn_cze = new map<int,ref alpBankNote>;
		bn_cze.Set(1,new alpBankNote("alp_Coin1",GetQuantity("alp_Coin1")));
		bn_cze.Set(2,new alpBankNote("alp_Coin2",GetQuantity("alp_Coin2")));
		bn_cze.Set(5,new alpBankNote("alp_Coin5",GetQuantity("alp_Coin5")));
		bn_cze.Set(10,new alpBankNote("alp_Money10",GetQuantity("alp_Money10")));
		bn_cze.Set(20,new alpBankNote("alp_Money20",GetQuantity("alp_Money20")));
		bn_cze.Set(50,new alpBankNote("alp_Money50",GetQuantity("alp_Money50")));
		bn_cze.Set(100,new alpBankNote("alp_Money100",GetQuantity("alp_Money100")));
		bn_cze.Set(500,new alpBankNote("alp_Money500",GetQuantity("alp_Money500")));
		bn_cze.Set(1000,new alpBankNote("alp_Money1000",GetQuantity("alp_Money1000")));
		alp_BankNotes.Set( id, bn_cze );		
	}

	private void SetUScurrency( int id, float rate, float range ) {
		alp_Currencies.Set(id, new alpCurrency(id,"#STR_usd_name",rate,range));
		map<int,ref alpBankNote> bn_usd = new map<int,ref alpBankNote>;
		bn_usd.Set(1,new alpBankNote("alp_USD1",GetQuantity("alp_USD1")));
		bn_usd.Set(5,new alpBankNote("alp_USD5",GetQuantity("alp_USD5")));
		bn_usd.Set(10,new alpBankNote("alp_USD10",GetQuantity("alp_USD10")));
		bn_usd.Set(20,new alpBankNote("alp_USD20",GetQuantity("alp_USD20")));
		bn_usd.Set(50,new alpBankNote("alp_USD50",GetQuantity("alp_USD50")));
		bn_usd.Set(100,new alpBankNote("alp_USD100",GetQuantity("alp_USD100")));
		bn_usd.Set(500,new alpBankNote("alp_USD500",GetQuantity("alp_USD500")));
		alp_BankNotes.Set( id, bn_usd );		
	}	

	int GetQuantity(string type )
	{
		int quantity = 1;
		string subclass_path = "CfgVehicles " + type + " nominalQuantity";
		quantity = GetGame().ConfigGetInt(subclass_path);
		return quantity;
	}
	
	map<int, ref alpCurrency> GetCurrencies() { return alp_Currencies; }
	alpCurrency GetCurrency(int id) { return alp_Currencies.Get(id); }
	
	float GetCurrencyRate(int currencyID )
	{
		float rate = 0;
		if ( alp_Currencies )
		{
			alpCurrency currency = alp_Currencies.Get( currencyID );
			if ( currency ) rate = currency.Rate;
		}							
		return rate;
	}
}

class alpCurrency 
{
	int ID;
	string Name;
	float Rate;
	float Offset;
	
	void alpCurrency(int id,string name, float rate, float offset)
	{
		ID = id;
		Name = name;
		Rate = rate;
		Offset = offset;
	}
	
	float GetRate() { return Rate; }
	float GetOffset() { return Offset; }
}