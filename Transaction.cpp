#include "Transaction.h"

Transaction::Transaction()
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
ostream& operator <<(ostream& output, Transaction& t)
{
	return output;
}
Transaction::~Transaction()
{
}

int Transaction::getCustomerID() const
{
	return this->customerID;
}

void Transaction::display()
{
	if (type == 'C')
	{
		cout << "Customer: " << customerID
			<< "\n" << "Borrowed: " << releaseMonth << " " << releaseYear << " " << majorActorFirstName << " " << majorActorLastName << endl;
	}
	else
	{
		cout << "Customer: " << customerID
			<< "\n" << "Borrowed: " << title << endl;
	}
}

char Transaction::getType() const
{
	return this->type;
}