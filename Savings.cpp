/*************************************************************************
* AUTHOR     	 : Tons
* STUDENT ID 	 : 705556
* ASSIGNMENT #   : Saddleback Bank - OOP
* CLASS			 : CS1B
* SECTION		 : TTh: 8:00a
* DUE DATE		 : 12/9/14
*************************************************************************/

#include "Savings.h"

/*************************************************************************
 * 	CONSTRUCTORS & DESTRUCTOR
 *************************************************************************/
Savings::Savings()
{
	// Assignment
	interestRate = 0;
}

Savings::Savings(Date   openingDate,
				 string name,
				 int    accountNum,
				 float  balance,
				 float  intRate)
	:Account(openingDate,
			 name,
			 accountNum,
			 balance)
{
	// Processing - Calls method SetInterestRate
	SetInterestRate(intRate);
}

Savings::~Savings(){}

void Savings::SetAllValues(Date   openingDate,
						   string name,
						   int    accountNum,
						   float  balance,
						   float  intRate)
{
	// Processing - Calls method SetAllValues
	Account::SetAllValues(openingDate,
						  name,
						  accountNum,
						  balance);

	// Processing - Calls method SetInterestRate
	SetInterestRate(intRate);
}

void Savings::SetInterestRate(float intRate)
{
	// Assignment
	interestRate = intRate;
}

bool Savings::Withdrawal(Date  today,
						 float amount)
{
	bool valid; // CALC - Valid or invalid

	// Processing - Determines if withdrawal can take place
	if((GetBalance() - amount) < 0)
	{
		// Assignment
		valid = false;
	}
	else
	{
		// Processing - Calls method Withdrawal
		Account::Withdrawal(today,
							amount);

		// Assignment
		valid = true;
	}

	return valid;
}

void Savings::UpdateAcct(Date today)
{
	/*********************************************************************
	 * 	CONSTANTS
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

	// Processing - Calls method GetDate
	today.GetDate(currentMonth,
				  currentDay,
				  currentYear);

	// Processing - Calls method GetLastTransDate and assign
	lastAccDate = GetLastTransDate();

	// Processing - Calls method GetDate
	lastAccDate.GetDate(lastAccMonth,
						lastAccDay,
						lastAccYear);

	// Assignments
	monthDifference = currentMonth - lastAccMonth;
	dayDifference   = currentDay   - lastAccDay;
	yearDifference  = currentYear  - lastAccYear;

	// Processing - Calculates the month difference
	monthDifference += (NUM_MONTHS_IN_YEAR * yearDifference);

	// Processing - Calls method UpdateAcct
	Account::UpdateAcct(today);

	// Processing - Deposits interest earned if monthDifference > 0
	if(monthDifference != 0)
	{
		for(int i = 0; i < monthDifference; i++)
		{
			// Processing - Calls method Deposit, GetInterestRate, and
			// 				GetBalance
			Account::Deposit(today,
							 GetInterestRate() * GetBalance());
		}
	}
}

float Savings::GetInterestRate() const
{
	return interestRate;
}
