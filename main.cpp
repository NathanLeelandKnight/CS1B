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
* Saddleback Bank - OOP
* ________________________________________________________________________
* This program will read in from an input file the opening accounts.
* 	It will store the opening date, name, amount, and type of account.
* 	A series of transaction will be read in from another input file, and
* 	the program will process the them. This program will use a base class,
* 	called account, and derived classes, called Checking, Savings, and
* 	MoneyMarket. There will also be composed of classes called Bank and
* 	Date. After processing the transactions the program will output the
* 	results to an output file.
* ________________________________________________________________________
* INPUT:
* 	output : Used for outputting
* 	list   : A linked list for data type Accounts
*
* OUTPUT:
*   output : Used for outputting
* 	oFile  : File used for outputting
*************************************************************************/

int main()
{
	ostringstream output; // CALC & OUT - Used for output
	ofstream      oFile;  // OUT        - Variable for output
	Bank          list;	  // CALC       - Linked list for Accounts

	// Processing - Associates oFile.txt with oFile
	oFile.open("oFile.txt");

	// Processing - Calls function PrintHeader
	PrintHeader("Saddleback Bank - OOP",
				'A',
				6,
				output);

	// Output
	cout  << output.str();
	oFile << output.str();

	// Processing - Calls function OutputHeading
	OutputHeading(oFile);

	// Processing - Calls function CreateList
	CreateList(oFile,
		       list);

	// Processing - Calls function Transactions
	Transactions(oFile,
			     list);

	// Output
	list.OutputList();

	return 0;
}
