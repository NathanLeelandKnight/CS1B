/*************************************************************************
* AUTHOR     	 : Tons
* STUDENT ID 	 : 705556
* ASSIGNMENT #   : Saddleback Bank - OOP
* CLASS			 : CS1B
* SECTION		 : TTh: 8:00a
* DUE DATE		 : 12/9/14
*************************************************************************/

#include "Checking.h"

/*************************************************************************
 * 	CONSTRUCTORS & DESTRUCTOR
 *************************************************************************/
Checking::Checking()
{
	overdraftPenalty = 0;
}

Checking::Checking(Date   openingDate,
				   string name,
				   int    accountNum,
				   float  balance,
				   float  overdraftFee)
	:Account(openingDate,
			 name,
			 accountNum,
			 balance)
{
	// Processing - Calls method SetOverdraftFee
	SetOverdraftFee(overdraftFee);
}

Checking::~Checking(){}

/*************************************************************************
 * 	MUTATORS
 * 	----------------------------------------------------------------------
 * 	SetAllValues
 * 	SetOverdraftFee
 * 	Withdrawal
 * 	UpdateAcct
 *************************************************************************/
void Checking::SetAllValues(Date   openingDate,
							string name,
							int    accountNum,
							float  balance,
							float  overdraftFee)
{
	// Processing - Calls method SetAllValues
	Account::SetAllValues(openingDate,
						  name,
						  accountNum,
						  balance);

	// Processing - Calls method SetOverdraftFee
	SetOverdraftFee(overdraftFee);
}

void Checking::SetOverdraftFee(float overdraftFee)
{
	// Assignment
	overdraftPenalty = overdraftFee;
}

// Virtual****
bool Checking::Withdrawal(Date  today,
						  float amount)
{
	bool valid; // CALC - Valid or invalid

	/*********************************************************************
	 * Processing - Selection statement that checks if the Withdrawal
	 * 				is possible. If it is, it will call Account Withdrawal
	 *********************************************************************/
	if((GetBalance() - amount) < -200)
	{
		// Assignment
		valid = false;
	}
	else
	{
		// Processing - Checks if Account needs to be overdraft charged
		if(GetBalance() < amount)
		{
			// Processing - Calls method Withdrawal
			Account::Withdrawal(today,
								GetOverdraftFee());
		}
		// Processing - Calls method Withdrawal
		Account::Withdrawal(today,
							amount);

		// Assignment
		valid = true;
	}

	return valid;
}

// Virtual****
void Checking::UpdateAcct(Date today)
{
	/*********************************************************************
	 * 	CONSTANT
	 * 	------------------------------------------------------------------
	 * 	USED FOR PROCESSING
	 * 	------------------------------------------------------------------
	 * 	NUM_MONTHS_IN_YEAR : Number of months in a year
	 *********************************************************************/
	const int NUM_MONTHS_IN_YEAR = 12;

	Date  lastAccDate;		// CALC - Last date account was accessed
	int   currentMonth;		// CALC - Current month
	int   currentDay;		// CALC - Current day
	int   currentYear;		// CALC - Current year
	int   lastAccMonth;		// CALC - Last access month
	int   lastAccDay;		// CALC - Last access day
	int   lastAccYear;		// CALC - Last access year
	int   monthDifference;	// CALC - Month difference
	int   dayDifference;	// CALC - Day difference
	int   yearDifference;	// CALC - Year difference
	float overDraftCharge;	// CALC - Over draft charge

	// Processing - Calls method GetDate
	today.GetDate(currentMonth,
				  currentDay,
				  currentYear);

	// Assignment
	lastAccDate = GetLastTransDate();

	// Processing - Calls method GetDate
	lastAccDate.GetDate(lastAccMonth,
						lastAccDay,
						lastAccYear);

	// Processing - Finds month, day, year difference
	monthDifference = currentMonth - lastAccMonth;
	dayDifference   = currentDay   - lastAccDay;
	yearDifference  = currentYear  - lastAccYear;

	// Processing - Finds total month difference
	monthDifference += (NUM_MONTHS_IN_YEAR * yearDifference);

	// Processing - Calls method UpdateAcct
	Account::UpdateAcct(today);

	/*********************************************************************
	 * Processing - Checks to see if Account needs to be charged an
	 * 				overdraft fee. If so, then it will calculate the total
	 * 				overdraft charged based on how many months have passed
	 *********************************************************************/
	if(GetBalance() < 0 && monthDifference != 0)
	{
		// Assignment
		overDraftCharge = OVERDRAFT_FEE * float(monthDifference);

		// Processing - Calls method Withdrawal
		Account::Withdrawal(today,
				   	   	    overDraftCharge);
	}
}

/*************************************************************************
 * 	ACCESSORS
 * 	----------------------------------------------------------------------
 * 	GetOverdraftFee
 *************************************************************************/
float Checking::GetOverdraftFee() const
{
	return overdraftPenalty;
}






