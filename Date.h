/*************************************************************************
* AUTHOR     	 : Tons
* STUDENT ID 	 : 705556
* ASSIGNMENT #   : Saddleback Bank - OOP
* CLASS			 : CS1B
* SECTION		 : TTh: 8:00a
* DUE DATE		 : 12/9/14
*************************************************************************/

#ifndef DATE_H_
#define DATE_H_

#include <ctime>
#include <iostream>

using namespace std;

class Date
{
public:

	/*****************************************************
	     CONSTRUCTORS & DESTRUCTOR
	 *****************************************************/
	Date();
	Date(int month,
		 int day,
		 int year);

	~Date();

	/*****************************************************
	     MUTATORS
	 *****************************************************/
	void SetDate(int month,
			     int day,
				 int year);

	/******************************************************
	    ACCESSORS
	 ******************************************************/
	void GetDate(int &month,
				 int &day,
				 int &year) const;
	int  GetYear()          const;
	int  GetMonth()         const;
	int  GetDay()           const;

	// Displays in MM/DD/YYYY format
	void DisplayDate()      const;

private:
	int dateMonth;
	int dateDay;
	int dateYear;
};

#endif /* DATE_H_ */
