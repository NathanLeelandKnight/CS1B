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
 * FUNCTUION OutputOpenAcct
 *________________________________________________________________________
 * OutputOpenAcct
 * 	This function will receive input as follows: oFile,
 * 												 setDate,
 * 												 accountType,
 * 												 name,
 * 												 accountNum,
 * 												 amount
 *
 * RETURNS: nothing
 * 	It will instead output the newly open account
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		oFile         : Has to be previously defined
 * 		setDate       : Has to be previously defined
 * 		accountType   : Has to be previously defined
 * 		name          : Has to be previously defined
 * 		accountNum    : Has to be previously defined
 * 		amount        : Has to be previously defined
 *
 * POST-CONDITIONS
 * 		This function will output the accounts information.
 ************************************************************************/
void OutputOpenAcct(ofstream &oFile,      // OUT - Used for output
					Date     setDate,	  // OUT - Date
					string   accountType, // OUT - Account type
					string   name,		  // OUT - Name
					int      accountNum,  // OUT - Account number
					float    amount)      // OUT - Amount
{
	// Output
	oFile << left;
	oFile << "OPEN ";

	// Processing - Uppercases accountType
	for(int i = 0; i < accountType.size(); i++)
	{
		accountType[i] = toupper(accountType[i]);
	}

	// Processing - Stores string if true
	if(accountType[0] == 'M')
	{
		// Assignment
		accountType = "Money Market";
	}

	// Output
	oFile << setw(14) << accountType;

	int month; // IN & OUT - Month of date
	int day;   // IN & OUT - Day of date
	int year;  // IN & OUT - Year of date

	// Processing - Calls method GetDate
	setDate.GetDate(month,
					day,
					year);

	// Output - The date
	if(month < 10)
	{
		oFile << '0';
	}
	oFile << month << '/';
	if(day < 10)
	{
		oFile << '0';
	}
	oFile << day   << '/'
		  << year  << "   ";

	// Output - Account information
	oFile << setw(ACCT_COL)       << accountNum;
	oFile << setw(NAME_COL)       << name;
	oFile << '$';
	oFile << right;
	oFile << setprecision(2)      << fixed;
	oFile << setw(AMOUNT_COL - 1) << amount;
	oFile << "   $";
	oFile << setw(BAL_COL - 4)    << amount;
	oFile.unsetf(std::ios_base::floatfield);
	oFile << setprecision(6);
	oFile << endl;
	oFile << right;
}
