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

Return::Return(const int customerID, char type, const string title, const string director, int releaseYear, const string majorActorFirstName, const string majorActorLastName, const int releaseMonth)
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

ostream& Return::display(ostream& output)
 {
	if (type == 'C')
	{
		output << "Customer: " << customerID
			<< "\n" << "Returned: " << title << " with " << majorActorFirstName << " " << majorActorLastName << endl;
	}
	else
	{
		output << "Customer: " << customerID
			<< "\n" << "Borrowed: " << title << endl;
	}

	return output;
}
