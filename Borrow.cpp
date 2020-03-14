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

Borrow::Borrow(const int customerID, char type, const string title, const string director, int releaseYear, const string majorActorFirstName, const string majorActorLastName, const int releaseMonth)
{
	this->customerID = customerID;
	this->type = type;
	this->title = title;
	this->director = director;
	this->releaseYear = releaseYear;
	this->majorActorFirstName = majorActorFirstName;
	this->majorActorLastName = majorActorLastName;
	this->releaseMonth = releaseMonth;
}

 void Borrow::display(ostream&output) 
{
	if (b.type == 'C')
	{
		output << "Customer: " << customerID
			<< "\n" << "Borrowed: " << title << " with " << majorActorFirstName << " " << majorActorLastName << endl;
	}
	else
	{
		output << "Customer: " << b.customerID
			<< "\n" << "Borrowed: " << title << endl;
	}

}