/*************************************************************************
* AUTHOR     	 : Tons
* STUDENT ID 	 : 705556
* ASSIGNMENT #   : Saddleback Bank - OOP
* CLASS			 : CS1B
* SECTION		 : TTh: 8:00a
* DUE DATE		 : 12/9/14
*************************************************************************/

#ifndef MONEYMARKET_H_
#define MONEYMARKET_H_

#include "Account.h"
#include "Savings.h"

using namespace std;

/*************************************************************************
 * 	CONSTANTS
 * 	----------------------------------------------------------------------
 * 	USED FOR PROCESSING
 * 	----------------------------------------------------------------------
 * 	MM_INTEREST    : Interest rate
 * 	WITHDRAWAL_FEE : Withdrawal fee
 *************************************************************************/
const float MM_INTEREST = .20;
const float WITHDRAWAL_FEE = 1.50;

class MoneyMarket: public Savings
{
public:
	/*****************************************************
	     CONSTRUCTORS & DESTRUCTOR
	 *****************************************************/
	MoneyMarket();
	MoneyMarket(Date   openingDate,
			    string name,
			    int    accountNum,
			    float  balance,
			    float  intRate,
			    float  withdrPenalty);

	virtual ~MoneyMarket();

	/*****************************************************
	     MUTATORS
	 *****************************************************/
	void SetAllValues(Date   openingDate,
					  string name,
					  int    accountNum,
					  float  balance,
					  float  intRate,
					  float  withdrPenalty);

	void SetWithdrawalPenalty(float withdrPenalty);

	virtual bool  Withdrawal(Date  today,
			                 float amount);

	/******************************************************
	    ACCESSORS
	 ******************************************************/
	float GetWithdrawalPenalty() const;

protected:
	float withdrawalPenalty;
};

#endif /* MONEYMARKET_H_ */
