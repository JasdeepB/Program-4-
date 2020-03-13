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
	this->customerID = customerID;
}

Customer::~Customer()
{
}

int& Customer::getCustomerID()
{
	int& ptr = this->customerID;
	return ptr;
}

void Customer::addTransaction(string transactionInfo)
{
	this->transactions.push_back(transactionInfo);
}

void Customer::showAllTransactions()
{
	if (this->transactions.empty())
	{
		cout << "There is no transaction history for this customer" << endl;
	}
	else
	{
		for (auto it = this->transactions.end() - 1; it != this->transactions.begin() - 1; it--)
		{
			cout << *it << endl;
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
