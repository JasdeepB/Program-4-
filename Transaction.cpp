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
//ostream& Transaction::operator <<(ostream& output, Transaction& t)
//{
//	return t.display(output);
//}
Transaction::~Transaction()
{
}

int Transaction::getCustomerID() const
{
	return this->customerID;
}

char Transaction::getType() const
{
	return this->type;
}