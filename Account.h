/*************************************************************************
* AUTHOR     	 : Tons
* STUDENT ID 	 : 705556
* ASSIGNMENT #   : Saddleback Bank - OOP
* CLASS			 : CS1B
* SECTION		 : TTh: 8:00a
* DUE DATE		 : 12/9/14
*************************************************************************/

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>
#include <iomanip>
#include <iostream>
#include <limits>
#include <ios>
#include "Date.h"
using namespace std;

class Account
{
public:
	/*****************************************************
	     CONSTRUCTORS & DESTRUCTOR
	 *****************************************************/
	Account();
	Account(Date   openingDate,
			string name,
		    int    accountNum,
			float  balance);

	virtual ~Account();

	/*****************************************************
	     MUTATORS
	 *****************************************************/
	void SetAllValues(Date   openingDate,
				      string name,
				      int    accountNum,
				      float  balance);

	void SetValue(string name);
	void SetValue(int    accountNum);
	void SetValue(float  balance);
	void SetValue(Date   openingDate);

	/*********************************************************************
	 * Deposit
	 * -------------------------------------------------------------------
	 * Adds the amount into the account
	 *********************************************************************/
	 void Deposit(Date  today,
			      float amount);

	/*********************************************************************
	 * Withdrawal
	 * ------------------------------------------------------------------
	 * Deducts amount from account unless there are insufficient funds
	 * - returns FALSE if withdrawal can't be perform
	 *********************************************************************/
	virtual bool Withdrawal(Date  today,
			                float amount);

	/*********************************************************************
	 * TransferFunds
	 * ------------------------------------------------------------------
	 * Transfers amount from the transferAcct to this account
	 * (Withdrawal from transferAcct - Deposit to this Acct)
	 * - returns FALSE if the transfer can't be performed
	 *   either due to invalid account options or insufficient
	 *   funds in the transferAcct
	 * - returns TRUE if transfer is completed
	 *********************************************************************/
	bool TransferFunds(Date    today,
			           Account *transferAcct,
			           float   amount);
	/*********************************************************************
	 * Update Acct -
	 * ------------------------------------------------------------------
	 * Updates interest and overdraft charges
	 *       based on the difference in months between the
	 *       lastAccessDate and today
	 * This should be called with each transaction
	 ********************************************************************/
	virtual void UpdateAcct(Date today);

	// SetNext - sets the next attribute to point to accountToLink
	void SetNext(Account *accountToLink);

	/******************************************************
	    ACCESSORS
	 ******************************************************/
	Date   GetOpenDate()	  const;
	string GetName() 		  const;
	int    GetAcctNum()       const;
	float  GetBalance()       const;
	Date   GetLastTransDate() const;

	// GetNext - returns the address next is pointing to
	Account *GetNext()        const;

protected:
	Account *next;			// CALC     - Pointer for list
	string  clientName;		// IN & OUT - Name of client
	int     acctNumber;		// IN & OUT - Account number
	float   currentBalance; // IN & OUT - Current balance
	Date    openDate;		// IN & OUT - Opening date
	Date    lastAccessDate;	// IN & OUT - Last date account was accessed
};

#endif /* ACCOUNT_H_ */
