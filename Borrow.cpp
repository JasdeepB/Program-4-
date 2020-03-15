// ------------------------------------------------ Borrow.cpp -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the implementation file for the borrow class. This is a subclass of transaction
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------
#include "Borrow.h"
//constructors
Borrow::Borrow()
{
	this->type = 0;
	this->title = "";
	this->director = "";
	this->majorActorFirstName = "";
	this->majorActorLastName = "";
	this->releaseMonth = 0;
	this->releaseYear = 0;
	this->customerID = 0;
}
//Classic
Borrow::Borrow(const int customerID, const char type, const string title, const int releaseMonth, const int releaseYear, const string majorActorFirstName, const string majorActorLastName)
{
	this->type = type;
	this->title = title;
	this->director = "";
	this->majorActorFirstName = majorActorFirstName;
	this->majorActorLastName = majorActorLastName;
	this->releaseMonth = releaseMonth;
	this->releaseYear = releaseYear;
	this->customerID = customerID;
}
//Funny
Borrow::Borrow(const int customerID, char type, const string title, int releaseYear)
{
	this->type = type;
	this->title = title;
	this->director = "";
	this->majorActorFirstName = "";
	this->majorActorLastName = "";
	this->releaseMonth = 0;
	this->releaseYear = releaseYear;
	this->customerID = customerID;
}
//Drama
Borrow::Borrow(const int customerID, char type, const string director, string title)
{
	this->type = type;
	this->title = title;
	this->director = director;
	this->majorActorFirstName = "";
	this->majorActorLastName = "";
	this->releaseMonth = 0;
	this->releaseYear = 0;
	this->customerID = customerID;
}
//end constructors

// -------------------------------- display --------------------------------
// Description
// display: prints out the transaction
// preconditions: none
// postconditions: none
// -----------------------------------------------------------------------------
void Borrow::display() 
{
	if (type == 'C')
	{
		cout << "\nCustomer: " << customerID
			<< "\n" << "Borrowed: " << title << " " << releaseMonth<< " " << releaseYear<< " " << majorActorFirstName << " " << majorActorLastName << "\n\n";
	}
	else
	{
		cout << "\nCustomer: " << customerID
			<< "\n" << "Borrowed: " << title << "\n\n";
	}
	
}
//end display
