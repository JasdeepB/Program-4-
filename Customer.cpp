#include "Customer.h"

Customer::Customer()
{
	this->firstName = "";
	this->lastName = "";
	this->customerID = 0;
}

Customer::Customer(int ID, string firstName, string lastName)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->customerID = ID;
}

Customer::~Customer()
{
	for (int i = 0; i < transactions.size(); i++) {
		delete transactions[i];
	}

}

int Customer::getCustomerID()
{
	return this->customerID;
}

void Customer::addTransaction(Transaction *t)
{
	transactions.push_back(t);
}

void Customer::showAllTransactions()
{
	if (!this->transactions.empty())
	{
		for (int i = 0; i < this->transactions.size(); i++)
		{
			if (transactions[i]->getType() == 'R') {
				transactions[i]->display();
				
			}
			else {
				transactions[i]->display();
				
			}
			
		}
	}
}

bool Customer::operator==(const Customer& otherCustomer) const
{
	return (this->customerID == otherCustomer.customerID);
}

bool Customer::operator!=(const Customer& otherCustomer) const
{
	return !(this->customerID == otherCustomer.customerID);
}

ostream& operator<<(ostream& output, Customer& otherCustomer)
{
	output << "Customer Name: " << otherCustomer.firstName << " " << otherCustomer.lastName << " ID----> " << otherCustomer.customerID << endl;
	return output;
}
