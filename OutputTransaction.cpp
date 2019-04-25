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
 * FUNCTUION OutputTransaction
 *________________________________________________________________________
 * OutputTransaction
 * 	This function will receive input as follows: oFile,
 * 												 list,
 * 												 setDate,
 * 												 valid,
 * 												 accountNum,
 * 												 accountNumTwo,
 * 												 amount,
 * 												 transaction
 *
 * RETURNS: nothing
 * 	It will instead output a transaction.
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		oFile          : Has to be previously defined
 * 		list           : Has to be previously defined
 * 		setDate        : Has to be previously defined
 * 		valid          : Has to be previously defined
 * 		accountNum     : Has to be previously defined
 * 		accountNumTwo  : Has to be previously defined
 * 		amount         : Has to be previously defined
 * 		transaction    : Has to be previously defined
 *
 * POST-CONDITIONS
 * 		This function will output the transaction.
 ************************************************************************/
void OutputTransaction(ofstream &oFile,       // OUT  - Output file
					   Bank     &list,		  // CALC - List variable
					   Date     setDate,	  // OUT  - Date
					   bool     valid,		  // CALC - Valid or invalid
					   int      accountNum,	  // OUT  - Account number
					   int      accountNumTwo,// OUT  - Account number two
					   float    amount,       // OUT  - Amount
					   string   transaction)  // OUT  - Transaction
{
	Account accountInfo;    // CALC & OUT - Account object
	Account accountInfoTwo; // CALC & OUT - Account two object
	int     month;			// OUT        - Month
	int     day;			// OUT        - Day
	int     year;			// OUT        - Year
	float   balance;		// OUT        - Balance
	string  name;			// OUT        - Name

	/*********************************************************************
	 * Processing - Selection statement that will determine the appropriate
	 * 				output message to output. If the transaction is
	 * 				valid, this function will output the transaction. If
	 * 				not, it will output why the transaction cannot be
	 * 				processed
	 *********************************************************************/
	if(accountNum == accountNumTwo)
	{
		// Output
		oFile << endl;
		oFile << "*** ERROR - CAN\'T TRANSFER INTO THE SAME "
			  << "ACCOUNT ***";
		oFile << endl;
	}
	else if(valid)
	{
		// Assignments
		accountInfo = list.FindAccount(accountNum);
		name        = accountInfo.GetName();
		balance     = accountInfo.GetBalance();

		// Output
		oFile << left;
		oFile << ' ';
		oFile << setw(TRANS_COL - 1) << transaction;

		// Processing - Calls method GetDate
		setDate.GetDate(month,
						day,
						year);

		// Output - Date
		if(month < 10)
		{
			oFile      << '0';
		}
		oFile << month << '/';
		if(day < 10)
		{
			oFile << '0';
		}
		oFile << day   << '/'
			  << year  << "   ";

		// Output - Transaction
		oFile << setw(ACCT_COL)       << accountNum;
		oFile << setw(NAME_COL)       << name;
		oFile << '$';
		oFile << right;
		oFile << setprecision(2)      << fixed;
		oFile << setw(AMOUNT_COL - 1) << amount;
		oFile << "   $";
		oFile << setw(BAL_COL - 4)    << balance;
		oFile.unsetf(std::ios_base::floatfield);
		oFile << setprecision(6);

		// Output - Additional information if it is a transfer
		if(transaction == "Transfer")
		{
			// Assignments
			accountInfoTwo = list.FindAccount(accountNumTwo);
			balance        = accountInfoTwo.GetBalance();

			// Output
			oFile << setw(FROM_COL - 2)     << accountNumTwo;
			oFile << "       $";
			oFile << right;
			oFile << setprecision(2)        << fixed;
			oFile << setw(FROM_BAL_COL - 6) << balance;
		}
	}
	else
	{
		// Output
		oFile << endl;

		// Processing - Outputs appropriate message
		switch(transaction[0])
		{
		case 'T': oFile << "*** TRANSFER FROM ";
				  oFile << accountNumTwo << " TO ";
				  oFile << accountNum    << " NOT ALLOWED! ***";
				  oFile << endl;
				  oFile << "***        DUE TO INSUFFICIENT FUNDS";
				  oFile << "        ***";
				  break;
		case 'W': oFile << "*** WITHDRAWAL FROM ";
				  oFile << accountNum    << " NOT ALLOWED! ***";
				  oFile << endl;
				  oFile << "***     DUE TO INSUFFICIENT FUNDS     ***";
		}
		oFile << endl;
	}

	// Output
	oFile << endl;
	oFile << setprecision(6);
	oFile.unsetf(std::ios_base::floatfield);
}
