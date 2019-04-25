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
 * FUNCTUION PrintHeader
 *________________________________________________________________________
 * PrintHeader
 * 	This function will receive input as follows: asNameF,
 * 												 asTypeF,
 * 												 asNumF
 *
 * RETURNS: nothing
 * 	It will instead output the print header for the particular assignment.
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		asNameF:  Assignment name has to be previously defined
 * 		asTypeF:  Assignment type has to be previously defined
 * 		asNumF :  Assingment number has to be previously defined
 * 		output :  Output has to be previously defined
 *
 * POST-CONDITIONS
 * 		This function will output the class heading.
 ************************************************************************/
void PrintHeader(string         asNameF, // IN - Assignment Name
				 char           asTypeF, // IN - Assignment type
				   	   	    	         //      (LAB/ASSIGNMENT)
				 int            asNumF,  // IN - Assignment
				            		     //      Number
				 ostringstream& output)  // IN - Output location
{
	// OUTPUT - Class heading.
	output << left;
	output << setfill('*');
	output << setw(55) << "*";
	output << setfill(' ');
	output << "\n* " << setw(14) << "PROGRAMMED BY" << ": Tons";
	output << "\n* " << setw(14) << "STUDENT ID"    << ": 705556";
	output << "\n* " << setw(14) << "CLASS"         << ": CS1B";
	output << "\n* " << setw(14) << "SECTION"       << ": TTh - 8:00a";
	output << "\n* ";

	/*********************************************************************
	 * PROCESSING - Selection statement that will determine whether the
	 * 				project is either a Lab or an Assignment.
	 ********************************************************************/
	if(toupper(asTypeF) == 'L')
	{
		output << "LAB #" << setw(9);
	}
	else
	{
		output << "ASSIGNMENT #" << setw(2);
	}

	// OUTPUT - Class heading
	output << asNumF       << ": " << asNameF;
	output << setfill('*') << endl;
	output << setw(55)     << "*"  << endl << endl;
	output << setfill(' ');
	output << right;
}

