/*************************************************************************
* AUTHOR     	 : Tons
* STUDENT ID 	 : 705556
* ASSIGNMENT #   : Saddleback Bank - OOP
* CLASS			 : CS1B
* SECTION		 : TTh: 8:00a
* DUE DATE		 : 12/9/14
*************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "Account.h"
#include "Date.h"
#include "Checking.h"
#include "Bank.h"

using namespace std;

/*************************************************************************
 * 	CONSTANTS
 * 	----------------------------------------------------------------------
 * 	USED FOR FORMATTING
 * 	----------------------------------------------------------------------
 * 	TRANS_COL    : Transaction column
 * 	DATE_COL     : Date column
 * 	ACCT_COL     : Account column
 * 	NAME_COL     : Name column
 * 	AMOUNT_COL   : Amount column
 * 	BAL_COL      : Balance column
 * 	FROM_COL     : From account column
 * 	FROM_BAL_COL : From account balance column
 *************************************************************************/
const int TRANS_COL    = 19;
const int DATE_COL     = 13;
const int ACCT_COL     = 8;
const int NAME_COL     = 23;
const int AMOUNT_COL   = 10;
const int BAL_COL      = 16;
const int FROM_COL     = 15;
const int FROM_BAL_COL = 18;

/*************************************************************************
 * FUNCTION PROTOTYPES - The following are prototypes for each function.
 ************************************************************************/

/*************************************************************************
 * CreateList
 * 	This function will receive input as follows: oFile
 * 												 list
 *
 * RETURNS:
 * 	A created list by reference
 ************************************************************************/
void CreateList(ofstream &oFile, // CALC & OUT - Used to output to a file
				Bank     &list); // CALC       - Variable to create list

/*************************************************************************
 * OutputHeading
 * 	This function will receive input as follows: oFile
 *
 * RETURNS: nothing
 * 	It will instead output the table header.
 ************************************************************************/
void OutputHeading(ofstream &oFile); // OUT - Output file variable

/*************************************************************************
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
 ************************************************************************/
void OutputOpenAcct(ofstream &oFile,      // OUT - Used for output
					Date     setDate,	  // OUT - Date
					string   accountType, // OUT - Account type
					string   name,		  // OUT - Name
					int      accountNum,  // OUT - Account number
					float    amount);     // OUT - Amount

/*************************************************************************
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
 ************************************************************************/
void OutputTransaction(ofstream &oFile,       // OUT  - Output file
					   Bank     &list,		  // CALC - List variable
					   Date     setDate,	  // OUT  - Date
					   bool     valid,		  // CALC - Valid or invalid
					   int      accountNum,	  // OUT  - Account number
					   int      accountNumTwo,// OUT  - Account number two
					   float    amount,       // OUT  - Amount
					   string   transaction); // OUT  - Transaction

/*************************************************************************
 * PrintHeader
 * 	This function will receive input as follows: asNameF,
 * 												 asTypeF,
 * 												 asNumF,
 * 												 output
 *
 * RETURNS: nothing
 * 	It will instead output the print header for the particular assignment.
 ************************************************************************/
void PrintHeader(string         asNameF, // IN - Assignment Name
				 char           asTypeF, // IN - Assignment type
				   	   	    	         //      (LAB/ASSIGNMENT)
				 int            asNumF,  // IN - Assignment
				            			 //      Number
				 ostringstream& output); // IN - Output location

/*************************************************************************
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
 ************************************************************************/
void ReadInAndReturnBankData(ifstream &inFile,        // IN - Variable for
													  //      file
							 Date     &readDate,	  // IN - Date
							 int      &accountNum,    // IN - Account number
							 float    &amount,        // IN - Amount
							 string   &transaction,   // IN - Transaction
							 int      &accountNumTwo);// IN - Account number
												      // 	 two

/*************************************************************************
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
 ************************************************************************/
void ReadInAndReturnOpenData(ifstream &inFile,      // CALC - File variable
						     Date     &readDate,    // IN   - Date
						     string   &name, 		// IN   - Name
						     int      &accountNum,  // IN   - Account number
						     float    &amount,      // IN   - Amount
						     string   &accountType);// IN   - Account Type

void Transactions(ofstream &oFile,
				  Bank     &list);

#endif /* HEADER_H_ */
