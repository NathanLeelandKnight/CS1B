/*************************************************************************
* AUTHOR     	 : Tons
* STUDENT ID 	 : 705556
* ASSIGNMENT #   : Saddleback Bank - OOP
* CLASS			 : CS1B
* SECTION		 : TTh: 8:00a
* DUE DATE		 : 12/9/14
*************************************************************************/

#include "MoneyMarket.h"

/*************************************************************************
 * 	CONSTRUCTORS & DESTRUCTOR
 *************************************************************************/
MoneyMarket::MoneyMarket()
{
	// Assignment
	withdrawalPenalty = 0;
}

MoneyMarket::MoneyMarket(Date   openingDate,
						 string name,
						 int    accountNum,
						 float  balance,
						 float  intRate,
						 float  withdrPenalty)
	:Savings(openingDate,
			 name,
			 accountNum,
			 balance,
			 intRate)
{
	// Processing - Calls method SetWithdrawalPenalty
	SetWithdrawalPenalty(withdrPenalty);
}

MoneyMarket::~MoneyMarket(){}

void MoneyMarket::SetAllValues(Date   openingDate,
							   string name,
							   int    accountNum,
							   float  balance,
							   float  intRate,
							   float  withdrPenalty)
{
	// Processing - Calls method SetAllValues
	Savings::SetAllValues(openingDate,
						  name,
						  accountNum,
						  balance,
						  intRate);

	// Processing - Calls method SetWithdrawalPenalty
	SetWithdrawalPenalty(withdrPenalty);
}

void MoneyMarket::SetWithdrawalPenalty(float withdrPenalty)
{
	// Assignment
	withdrawalPenalty = withdrPenalty;
}

bool MoneyMarket::Withdrawal(Date  today,
							 float amount)
{
	bool valid; // CALC - Valid or invalid

	// Processing - Checks if the transaction is valid or invalid
	if((GetBalance() - (amount + GetWithdrawalPenalty())) < 0)
	{
		// Assignment
		valid = false;
	}
	else
	{
		// Processing - Calls method Withdrawal and GetWithdrawalPenalty
		Account::Withdrawal(today,
							amount + GetWithdrawalPenalty());

		// Assignment
		valid = true;
	}
	return valid;
}

float MoneyMarket::GetWithdrawalPenalty() const
{
	return withdrawalPenalty;
}
