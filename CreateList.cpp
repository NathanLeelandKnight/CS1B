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
 * FUNCTUION CreateList
 *________________________________________________________________________
 * CreateList
 * 	This function will receive input as follows: oFile
 * 												 list
 *
 * RETURNS:
 * 	A created list by reference
 *________________________________________________________________________
 * PRE-CONDITIONS
 * 		oFile : Has to be previously defined
 * 		list  : Has to be previously defined
 *
 * POST-CONDITIONS
 * 		This function creates a list and returns by reference
 ************************************************************************/
void CreateList(ofstream &oFile, // CALC & OUT - Used to output to a file
				Bank     &list)  // CALC       - Variable to create list
{
	ifstream    inFile;			// CALC - File variable used to read in
	Account     *myAccount;		// CALC - Pointer used to create list
	Checking    *checkPtr;		// CALC - Pointer used to create list
	Savings     *savePtr;		// CALC - Pointer used to create list
	MoneyMarket *mmPtr;			// CALC - Pointer used to create list
	Date        setDate;		// IN   - Date of opening
	string      name;			// IN   - Name on account
	string      accountType;	// IN   - Account type
	int         accountNum;		// IN   - Account number
	float       amount;			// IN   - Account amount

	// Processing - associates file OpenAccts.txt with inFile
	inFile.open("OpenAccts.txt");

	/*********************************************************************
	 * Processing - While loop that will run until the end of the file.
	 * 				This loop will read in and create a list of accounts.
	 *********************************************************************/
	while(!inFile.eof())
	{
		// Processing - Calls function ReadInAndReturnOpenData
		ReadInAndReturnOpenData(inFile,
								setDate,
								name,
								accountNum,
								amount,
								accountType);

		// Processing - Switch that decides which derived class to create
		switch(accountType[0])
		{
		// Processing - Creates a Checking node
		case 'C': checkPtr = new Checking;

				  if(checkPtr != NULL)
				  {
					  // Processing - Calls method SetAllValues
					  checkPtr->SetAllValues(setDate,
											 name,
											 accountNum,
											 amount,
											 OVERDRAFT_FEE);
					  // Assignment
					  myAccount = checkPtr;
				  }
				  break;

		// Processing - Creates a Savings node
		case 'S': savePtr = new Savings;

				  if(savePtr != NULL)
				  {
					  // Processing - Calls method SetAllValues
				  	  savePtr->SetAllValues(setDate,
				  			  	  	  	    name,
				  			  	  	  	    accountNum,
				  			  	  	  	    amount,
				  			  	  	  	    SAVE_INTEREST);
				  	  // Assignment
				  	  myAccount = savePtr;
				  }
				  break;

		// Processing - Creates a MoneyMarket node
		case 'M': mmPtr = new MoneyMarket;

				  if(mmPtr != NULL)
				  {
					  // Processing - Calls method SetAllValues
					  mmPtr->SetAllValues(setDate,
							  	  	  	  name,
							  	  	  	  accountNum,
							  	  	  	  amount,
							  	  	  	  MM_INTEREST,
							  	  	  	  WITHDRAWAL_FEE);
					  // Assignment
					  myAccount = mmPtr;
				  }
		}
		// Processing - Calls method OpenAccount
		list.OpenAccount(myAccount);

		// Processing - Calls function OutputOpenAcct
		OutputOpenAcct(oFile,
					   setDate,
					   accountType,
					   name,
					   accountNum,
					   amount);
	}

	// Output
	oFile << endl;

	// Processing - Closes inFile
	inFile.close();
}
