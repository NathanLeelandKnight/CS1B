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
 * FUNCTUION OutputHeading
 *________________________________________________________________________
 * OutputHeading
 * 	This function will receive input as follows: oFile
 *
 * RETURNS: nothing
 * 	It will instead output the table header.
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		oFile : Has to be previously defined
 *
 * POST-CONDITIONS
 * 		This function will output the table heading.
 ************************************************************************/
void OutputHeading(ofstream &oFile)  // OUT - Output file variable
{
	/*********************************************************************
	 * OUTPUT - This will output the table heading for the assignment
	 *********************************************************************/
	oFile << left;
	oFile << setw(TRANS_COL)    << "TRANSACTION";
	oFile << setw(DATE_COL)     << "DATE";
	oFile << setw(ACCT_COL)     << "ACCT #";
	oFile << setw(NAME_COL)     << "ACCT NAME";

	oFile << right;
	oFile << setw(AMOUNT_COL)   << "AMOUNT";
	oFile << setw(BAL_COL)      << "BALANCE";
	oFile << setw(FROM_COL)     << "FROM ACCT#";
	oFile << setw(FROM_BAL_COL) << "FROM ACCT BAL";
	oFile << endl;

	oFile << setfill('-');
	oFile << setw(TRANS_COL)    << "       ";
	oFile << setw(DATE_COL)     << "   ";
	oFile << setw(ACCT_COL)     << "   ";
	oFile << setw(NAME_COL)     << "   ";

	oFile << left;
	oFile << setw(AMOUNT_COL)   << '-';
	oFile << setw(BAL_COL)      << "   ";
	oFile << setw(FROM_COL)     << "     ";
	oFile << setw(FROM_BAL_COL) << "     ";
	oFile << endl;
	oFile << right;
	oFile << setfill(' ');
}
