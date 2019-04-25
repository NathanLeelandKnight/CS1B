/*************************************************************************
* AUTHOR     	 : Tons
* STUDENT ID 	 : 705556
* ASSIGNMENT #   : Saddleback Bank - OOP
* CLASS			 : CS1B
* SECTION		 : TTh: 8:00a
* DUE DATE		 : 12/9/14
*************************************************************************/

#ifndef BANK_H_
#define BANK_H_

#include "Date.h"
#include "Checking.h"
#include "MoneyMarket.h"
using namespace std;

class Bank
{
public:
	/*****************************************************
	     CONSTRUCTORS & DESTRUCTOR
	 *****************************************************/
	Bank();
	~Bank();

	/*****************************************************
	 *   MUTATORS
	 *   -------------------------------------------------
	 *   OpenAccount
	 *   Deposit
	 *   Withdrawal
	 *   Transfer
	 *   FindAccount
	 *****************************************************/
	void OpenAccount(Account *newAcct);

	bool Deposit(Date  transDate,
			     int   acctNum,
				 float amount);

	bool Withdrawal(Date  transDate,
			     	int   acctNum,
					float amount);

	bool Transfer(Date  transDate,
				  int   acctNum,
				  float amount,
			      int   transFromAcctNum);

	Account FindAccount(int acctNum);

	/******************************************************
	 *  ACCESSORS
	 *  ---------------------------------------------------
	 *  OutputList
	 ******************************************************/
	// Output details on all accounts
	void OutputList() const;

protected:
	// Returns a pointer to an account
	Account *FindAccountPtr(int acctNum);

private:
	Account *head;			// CALC - Head of the list
	int     numberOfAccts;	// CALC - Number of accounts
};

#endif /* BANK_H_ */
