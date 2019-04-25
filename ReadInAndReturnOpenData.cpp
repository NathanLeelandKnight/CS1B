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
 * FUNCTUION ReadInAndReturnOpenData
 *________________________________________________________________________
 * ReadInAndReturnOpenData
 * 	This function will receive input as follows: inFile,
 * 												 readDate,
 * 												 name,
 * 												 accountNum,
 * 												 amount,
 * 												 accountType
 *
 * RETURNS: nothing
 * 	It will instead return all parameters by reference
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		inFile        : File variable
 * 		readDate      : Date opened
 * 		name          : Name on account
 * 		accountNum    : Account number
 * 		amount        : Amount at opening
 * 		accountType   : Type of account
 *
 * POST-CONDITIONS
 * 		This function will return all values by reference
 ************************************************************************/
void ReadInAndReturnOpenData(ifstream &inFile,      // CALC - File variable
						     Date     &readDate,    // IN   - Date
						     string   &name, 		// IN   - Name
						     int      &accountNum,  // IN   - Account number
						     float    &amount,      // IN   - Amount
						     string   &accountType) // IN   - Account Type
{
	int    month; // IN - Month of date
	int    day;   // IN - Day of date
	int    year;  // IN - Year of date

	// Input
	inFile >> month;
	inFile >> day;
	inFile >> year;
	inFile >> accountNum;
	inFile >> accountType;
	inFile >> amount;
	inFile.ignore(1000, ' ');
	getline(inFile, name);

	// Processing - Calls method SetDate
	readDate.SetDate(month, day, year);
}
