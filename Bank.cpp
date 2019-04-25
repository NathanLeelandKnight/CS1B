/*************************************************************************
* AUTHOR     	 : Tons
* STUDENT ID 	 : 705556
* ASSIGNMENT #   : Saddleback Bank - OOP
* CLASS			 : CS1B
* SECTION		 : TTh: 8:00a
* DUE DATE		 : 12/9/14
*************************************************************************/

#include "Bank.h"

/*************************************************************************
 * CONSTRUCTOR & DESTRUCTOR
 *************************************************************************/
Bank::Bank()
{
	// Assignments
	head          = NULL;
	numberOfAccts = 0;
}

Bank::~Bank(){}

/*************************************************************************
 * 	ACCESSORS
 * 	----------------------------------------------------------------------
 * 	OpenAccount
 * 	Deposit
 * 	Withdrawal
 * 	Transfer
 * 	FindAccount
 * 	FindAccountPtr
 *************************************************************************/
void Bank::OpenAccount(Account *newAcct)
{
	// Processing - Calls method SetNext
	newAcct->SetNext(head);

	// Assignment
	head = newAcct;
	numberOfAccts++;
}

bool Bank::Deposit(Date  transDate,
				   int   acctNum,
				   float amount)
{
	// Processing - Calls method FindAccountPtr and calls method Deposit
	FindAccountPtr(acctNum)->Deposit(transDate,
								 	 amount);

	return true;
}

bool Bank::Withdrawal(Date  transDate,
					  int   acctNum,
					  float amount)
{
	bool valid; // CALC - Valid or invalid

	// Processing - Checks if valid transaction
	valid = FindAccountPtr(acctNum)->Withdrawal(transDate,
												amount);

	return valid;
}

bool Bank::Transfer(Date  transDate,
					int   acctNum,
					float amount,
					int   transFromAcctNum)
{
	bool valid; // CALC - Valid or invalid

	// Processing - Checks if valid transaction
	valid = FindAccountPtr(acctNum)->
				TransferFunds(transDate,
				  	  	   	  FindAccountPtr(transFromAcctNum),
				  	  	   	  amount);

	return valid;
}

Account Bank::FindAccount(int acctNum)
{
	Account *sPtr;   // CALC       - Used to find account
	Account sObject; // CALC & OUT - Used to return account info
	bool    found;   // CALC       - Found or not found

	// Assignments
	found = false;
	sPtr  = head;

	// Processing - While loop that will search for account
	while(sPtr != NULL && !found)
	{
		// Processing - Sets to true if found. Traverses if not found
		if(sPtr->GetAcctNum() == acctNum)
		{
			// Assignment
			found = true;
		}
		else
		{
			// Assignment
			sPtr = sPtr->GetNext();
		}
	}

	// Assignment
	sObject = *sPtr;

	// Processing - Calls method SetNext
	sObject.SetNext(NULL);

	return sObject;
}

void Bank::OutputList() const
{
	Account *accPtr; // CALC & OUT - Pointer that will traverse the list

	// Assignment
	accPtr = head;

	// Formatting
	cout << setprecision(2) << fixed;

	/*********************************************************************
	 * Processing - While loop that will output the list
	 *********************************************************************/
	while(accPtr != NULL)
	{
		cout <<  accPtr->GetName()    << " has a balance of" << endl;
		cout <<  accPtr->GetBalance() << endl << endl;

		// Processing - Traverses the list
		accPtr = accPtr->GetNext();
	}
	// Set format back to default
	cout.unsetf(std::ios_base::floatfield);
	cout << setprecision(6);
}

Account *Bank::FindAccountPtr(int acctNum)
{
	Account *sPtr; // CALC & OUT - Return pointer
	bool    found; // CALC       - Found or not found

	// Assignments
	found = false;
	sPtr  = head;

	// Processing - While loop that will search for account
	while(sPtr != NULL && !found)
	{
		// Processing - Sets to true if found. Traverses if not found
		if(sPtr->GetAcctNum() == acctNum)
		{
			// Assignment
			found = true;
		}
		else
		{
			// Assignment
			sPtr = sPtr->GetNext();
		}
	}

	// Return
	return sPtr;
}
