#include "Borrow.h"

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

Borrow::Borrow(const int customerID, const char type, const int releaseMonth, const int releaseYear, const string majorActorFirstName, const string majorActorLastName)
{
	this->type = type;
	this->title = "";
	this->director = "";
	this->majorActorFirstName = majorActorFirstName;
	this->majorActorLastName = majorActorLastName;
	this->releaseMonth = releaseMonth;
	this->releaseYear = releaseYear;
	this->customerID = customerID;
}

Borrow::Borrow(const int customerID, char type, const string title, int releaseYear)
{
	this->type = 0;
	this->title = title;
	this->director = "";
	this->majorActorFirstName = "";
	this->majorActorLastName = "";
	this->releaseMonth = 0;
	this->releaseYear = releaseYear;
	this->customerID = customerID;
}

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



ostream& Borrow::display(ostream&output) 
{
	if (type == 'C')
	{
		output << "Customer: " << customerID
			<< "\n" << "Borrowed: " << releaseMonth<< " "<< releaseYear<< " " << majorActorFirstName << " " << majorActorLastName << endl;
	}
	else
	{
		output << "Customer: " << customerID
			<< "\n" << "Borrowed: " << title << endl;
	}
	return output;
}
