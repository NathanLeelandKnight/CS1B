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
 * FUNCTUION ReadInAndReturnBankData
 *________________________________________________________________________
 * ReadInAndReturnBankData
 * 	This function will receive input as follows: inFile,
 * 												 readDate,
 * 												 accountNum,
 * 												 amount,
 * 												 transaction,
 * 												 accountNumTwo
 *
 * RETURNS: nothing
 * 	It will instead return all parameters by reference
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		inFile         : File variable name
 * 		readDate       : Stores the date
 * 		accountNum     : Stores the account number
 * 		amount         : Stores the amount
 * 		transaction    : Stores the transaction type
 * 		accountNumTwo  : Stores the account two number
 *
 * POST-CONDITIONS
 * 		This function will read in the inFile.
 ************************************************************************/
void ReadInAndReturnBankData(ifstream &inFile,       // IN - Variable for
													 //      file
							 Date     &readDate,	 // IN - Date
							 int      &accountNum,   // IN - Account number
							 float    &amount,       // IN - Amount
							 string   &transaction,  // IN - Transaction
							 int      &accountNumTwo)// IN - Account number
												     // 	 two
{
	int month; // IN - Month of date
	int day;   // IN - Day of date
	int year;  // IN - Year of date

	// Input
	inFile >> month;
	inFile >> day;
	inFile >> year;
	inFile >> accountNum;
	inFile >> amount;
	inFile >> transaction;
	inFile.ignore(1000, '\n');

	// Processing - If transaction equal Transfer, read extra input
	if(transaction == "Transfer")
	{
		inFile >> accountNumTwo;
		inFile.ignore(1000, '\n');
	}

	// Processing - Calls method SetDate
	readDate.SetDate(month, day, year);
}
