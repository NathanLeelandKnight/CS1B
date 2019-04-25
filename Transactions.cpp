/*************************************************************************
* AUTHOR     	 : Tons
* STUDENT ID 	 : 705556
* ASSIGNMENT #   : Saddleback Bank - OOP
* CLASS			 : CS1B
* SECTION		 : TTh: 8:00a
* DUE DATE		 : 12/9/14
*************************************************************************/

#include "Header.h"

/*************************************************************************
 * FUNCTUION Transactions
 *________________________________________________________________________
 * Transactions
 * 	This function will receive input as follows: oFile
 * 												 list
 *
 * RETURNS: nothing
 * 	It will instead call the appropriate methods to carry out the
 * 	transactions
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		oFile : Has to be previously defined
 * 		list  : Has to be previously defined
 *
 * POST-CONDITIONS
 * 		This function will carry out transactions
 ************************************************************************/
void Transactions(ofstream &oFile,
				  Bank     &list)
{
	ifstream inFile;		// IN   - File variable for reading in input
	Date     setDate;		// IN   - Date of transaction
	bool     valid;			// CALC - Valid or invalid
	int      accountNum;	// IN   - Account number
	int      accountNumTwo;	// IN   - Account number two
	float    amount;		// IN   - Amount
	string   transaction;   // IN   - Transaction type

	// Processing - Associates BankData.txt with inFile
	inFile.open("BankData.txt");

	/*********************************************************************
	 * Processing - While loop that will run until the end of the file.
	 * 				this loop will determine which type of transaction to
	 * 				carry out based on the input file
	 *********************************************************************/
	while(!inFile.eof())
	{
		// Assignment
		accountNumTwo = 0;

		// Processing - Calls method ReadInAndReturnBankData
		ReadInAndReturnBankData(inFile,
								setDate,
								accountNum,
								amount,
								transaction,
								accountNumTwo);

		// Processing - Switch statement that will determine the transaction
		switch(transaction[0])
		{
		// Processing - Calls method Deposit
		case 'D': valid = list.Deposit(setDate,
							   	   	   accountNum,
							   	   	   amount);

				  break;

		// Processing - Calls method Withdrawal
		case 'W': valid = list.Withdrawal(setDate,
								  	  	  accountNum,
								  	  	  amount);

				  break;

		// Processing - Checks if accounts are the same
		case 'T': if(accountNum != accountNumTwo)
				  {
					  // Processing - Calls method Transfter
				  	  valid = list.Transfer(setDate,
										    accountNum,
										    amount,
										    accountNumTwo);
				  }
				  else
				  {
					  // Assignment
					  valid = false;
				  }
		}

		// Processing - Calls function OutputTransaction
		OutputTransaction(oFile,
					      list,
					      setDate,
					      valid,
					      accountNum,
					      accountNumTwo,
					      amount,
					      transaction);
	}

	// Processing - Close inFile
	inFile.close();
}
