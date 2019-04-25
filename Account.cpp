/*************************************************************************
* AUTHOR     	 : Tons
* STUDENT ID 	 : 705556
* ASSIGNMENT #   : Saddleback Bank - OOP
* CLASS			 : CS1B
* SECTION		 : TTh: 8:00a
* DUE DATE		 : 12/9/14
*************************************************************************/

#include "Account.h"

/*************************************************************************
 *   CONSTRUCTORS & DECONSTRUCTOR
 *************************************************************************/
Account::Account()
{
	next = NULL;
	clientName.clear();
	acctNumber     = 0;
	currentBalance = 0;
}

Account::Account(Date   openingDate,
				 string name,
				 int    accountNum,
				 float  balance)
{
	// Processing - Calls method SetAllValues
	SetAllValues(openingDate,
				 name,
				 accountNum,
				 balance);
}

Account::~Account(){}

/*************************************************************************
 *   MUTATORS
 *   ---------------------------------------------------------------------
 *   SetAllValues
 *   SetValue
 *   Deposit
 *   Withdrawal
 *   TransferFunds
 *   UpdateAcct
 *   SetNext
 *************************************************************************/
void Account::SetAllValues(Date   openingDate,
						   string name,
						   int    accountNum,
						   float  balance)
{
	// Assignments
	openDate       = openingDate;
	clientName     = name;
	acctNumber     = accountNum;
	currentBalance = balance;
	lastAccessDate = openingDate;
}

void Account::SetValue(string name)
{
	// Assignment
	clientName = name;
}

void Account::SetValue(int accountNum)
{
	// Assignment
	acctNumber = accountNum;
}

void Account::SetValue(float balance)
{
	// Assignment
	currentBalance = balance;
}

void Account::SetValue(Date openingDate)
{
	// Assignment
	openDate = openingDate;
}

void Account::Deposit(Date  today,
					  float amount)
{
	// Processing - Calls method UpdateAcct
	UpdateAcct(today);

	// Add amount to currentBalance
	currentBalance += amount;
}

// Virtual****
bool Account::Withdrawal(Date  today,
						 float amount)
{
	// Processing - Calls method UpdateAcct
	UpdateAcct(today);

	// Subtract amount from currentBalance
	currentBalance -= amount;

	// Return
	return true;
}

bool Account::TransferFunds(Date    today,
							Account *transferAcct,
							float   amount)
{
	bool valid; // CALC & OUT - Valid or invalid

	// Processing - Calls method UpdateAcct
	UpdateAcct(today);

	// Processing - Call UpdateAcct for transferAcct
	transferAcct->UpdateAcct(today);

	/*********************************************************************
	 * Processing - Selection statement that will call account method
	 * 				Withdrawal if there are sufficient funds
	 *********************************************************************/
	if(transferAcct->GetBalance() < 0)
	{
		// Assignment
		valid = false;
	}
	else
	{
		// Processing - Calls method Withdrawal
		transferAcct->Withdrawal(today,
								 amount);

		// Assignment
		valid = true;
	}

	// Processing - Calls method Deposit if valid
	if(valid)
	{
		Deposit(today,
				amount);
	}

	// Return
	return valid;
}

// Virtual****
void Account::UpdateAcct(Date today)
{
	// Assignment
	lastAccessDate = today;
}

void Account::SetNext(Account *accountToLink)
{
	// Assignment
	next = accountToLink;
}

/*************************************************************************
 * 	ACCESSORS
 * 	----------------------------------------------------------------------
 * 	GetOpenDate
 * 	GetName
 * 	GetAcctNum
 * 	GetBalance
 * 	GetLastTransDate
 * 	GetNext
 *************************************************************************/
Date Account::GetOpenDate() const
{
	return openDate;
}

string Account::GetName() const
{
	return clientName;
}

int Account::GetAcctNum() const
{
	return acctNumber;
}

float Account::GetBalance() const
{
	return currentBalance;
}

Date Account::GetLastTransDate() const
{
	return lastAccessDate;
}

Account *Account::GetNext() const
{
	return next;
}
