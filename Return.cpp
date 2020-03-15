#include "Return.h"

Return::Return()
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

Return::Return(const string t, const int customerID, char type, const int releaseMonth, const int releaseYear, const string majorActorFirstName, const string majorActorLastName)
{
	this->type = type;
	this->title = t;
	this->director = "";
	this->majorActorFirstName = majorActorFirstName;
	this->majorActorLastName = majorActorLastName;
	this->releaseMonth = releaseMonth;
	this->releaseYear = releaseYear;
	this->customerID = customerID;
}

Return::Return(const int customerID, char type, const string title, int releaseYear)
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

Return::Return(const int customerID, char type, const string director, string title)
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


void Return::display()
 {
	if (type == 'C')
	{
		cout << "Customer: " << customerID
			<< "\n" << "Returned: " << title << " with " << majorActorFirstName << " " << majorActorLastName << endl;
	}
	else
	{
		cout << "Customer: " << customerID
			<< "\n" << "Returned: " << title << endl;
	}
}
