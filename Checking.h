/*************************************************************************
* AUTHOR     	 : Tons
* STUDENT ID 	 : 705556
* ASSIGNMENT #   : Saddleback Bank - OOP
* CLASS			 : CS1B
* SECTION		 : TTh: 8:00a
* DUE DATE		 : 12/9/14
*************************************************************************/

#ifndef CHECKING_H_
#define CHECKING_H_

#include "Account.h"
using namespace std;

/*************************************************************************
 * 	CONSTANT
 * 	----------------------------------------------------------------------
 * 	PROCESSING
 * 	----------------------------------------------------------------------
 * 	OVERDRAFT_FEE : Overdraft fee
 *************************************************************************/
const float OVERDRAFT_FEE = 20;

class Checking: public Account
{
public:
	/*****************************************************
	     CONSTRUCTORS & DESTRUCTOR
	 *****************************************************/

	Checking();
	Checking(Date   openingDate,
			 string name,
		     int    accountNum,
			 float  balance,
			 float  overdraftFee);

	virtual ~Checking();

	/*****************************************************
	     MUTATORS
	 *****************************************************/
	void SetAllValues(Date   openingDate,
					  string name,
					  int    accountNum,
					  float  balance,
					  float  overdraftFee);

	void SetOverdraftFee(float overdraftFee);

	virtual bool Withdrawal(Date  today,
			                float amount);

	virtual void UpdateAcct(Date today);

	/******************************************************
	    ACCESSORS
	 ******************************************************/
	float GetOverdraftFee() const;

protected:
	float overdraftPenalty; // CALC - Overdraft Penalty
};

#endif /* CHECKING_H_ */
