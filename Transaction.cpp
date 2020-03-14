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
	return t.display(output);
}
Transaction::~Transaction()
{
}

int Transaction::getCustomerID() const
{
	return this->customerID;
}

ostream & Transaction::display(ostream & output)
{
	if (type == 'C')
	{
		output << "Customer: " << customerID
			<< "\n" << "Borrowed: " << title << " with " << majorActorFirstName << " " << majorActorLastName << endl;
	}
	else
	{
		output << "Customer: " << customerID
			<< "\n" << "Borrowed: " << title << endl;
	}
	return output;
}

char Transaction::getType() const
{
	return this->type;
}