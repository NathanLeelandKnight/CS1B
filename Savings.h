/*************************************************************************
* AUTHOR     	 : Tons
* STUDENT ID 	 : 705556
* ASSIGNMENT #   : Saddleback Bank - OOP
* CLASS			 : CS1B
* SECTION		 : TTh: 8:00a
* DUE DATE		 : 12/9/14
*************************************************************************/

#ifndef SAVINGS_H_
#define SAVINGS_H_

#include "Account.h"

using namespace std;

/*************************************************************************
 * 	CONSTANTS
 * 	----------------------------------------------------------------------
 * 	USED FOR PROCESSING
 * 	----------------------------------------------------------------------
 * 	SAVE_INTEREST : Interest rate for savings account
 *************************************************************************/
const float SAVE_INTEREST = .10;

class Savings: public Account
{
public:

	/*****************************************************
	     CONSTRUCTORS & DESTRUCTOR
	 *****************************************************/
	Savings();
	Savings(Date   openingDate,
			string name,
			int    accountNum,
			float  balance,
			float  intRate);

	virtual ~Savings();

	/*****************************************************
	     MUTATORS
	 *****************************************************/
	void SetAllValues(Date   openingDate,
					  string name,
					  int    accountNum,
					  float  balance,
					  float  intRate);

	void SetInterestRate(float intRate);

	virtual bool Withdrawal(Date  today,
			                float amount);

	virtual void UpdateAcct(Date today);

	/******************************************************
	    ACCESSORS
	 ******************************************************/
	float GetInterestRate() const;

protected:
	float  interestRate; // CALC - Interest rate

private:
};

#endif /* SAVINGS_H_ */
