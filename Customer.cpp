// ------------------------------------------------ Customer.cpp -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the implementation file for the customer class. 
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------
#include "Customer.h"

//default constructor
Customer::Customer()
{
	this->firstName = "";
	this->lastName = "";
	this->customerID = 0;
}
//end default constructor

//constructor
Customer::Customer(int ID, string firstName, string lastName)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->customerID = ID;
}
//end constructor

//destructor
Customer::~Customer()
{
	for (int i = 0; i < transactions.size(); i++) {
	
		delete transactions[i];
	}

}
//end destructor

// -------------------------------- getCustomerID() --------------------------------
// Description
// getCustomerID(): returns an int that contains the ID number for a customer
// preconditions:valid customer object
// postconditions: int containing ID
// -----------------------------------------------------------------------------
int Customer::getCustomerID()
{
	return this->customerID;
}
//end getCustomerID

// -------------------------------- addTransaction() --------------------------------
// Description
//  addTransaction(): stores the transaction in the vector to all alter
// preconditions:valid transaction object
// postconditions: transaction added to transaction vector
// -----------------------------------------------------------------------------
void Customer::addTransaction(Transaction *t)
{
	transactions.push_back(t);
}
//end addTransaction

// -------------------------------- showAllTransaction() --------------------------------
// Description
//  showAllTransactions: displays all transactions store in the transactions vector
// preconditions:valid transaction vector
// postconditions:calls the transaction  subclasses display function.
// -----------------------------------------------------------------------------
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
//end showAllTransactions

// -------------------------------- operator== --------------------------------
// Description
// operator== : compares whether two customer objects are equal
// preconditions:two valid customer objects 
// postconditions: the equality of two customer objects has bee determined 
// -----------------------------------------------------------------------------
bool Customer::operator==(const Customer& otherCustomer) const
{
	return (this->customerID == otherCustomer.customerID);
}
//end operator==

// -------------------------------- operator!= --------------------------------
// Description
// operator== : compares whether two customer objects are not equal
// preconditions:two valid customer objects 
// postconditions: the non-equality of the two objects has been assessed
// -----------------------------------------------------------------------------
bool Customer::operator!=(const Customer& otherCustomer) const
{
	return !(this->customerID == otherCustomer.customerID);
}
//end operator !=

// -------------------------------- operator<< --------------------------------
// Description
// operator<< : outputs a formatted string with all relevant information about the customer object
// preconditions:valid output stream, valid customer object 
// postconditions: formatted string appears in output 
// -----------------------------------------------------------------------------
ostream& operator<<(ostream& output, Customer& otherCustomer)
{
	output << "Customer Name: " << otherCustomer.firstName << " " << otherCustomer.lastName << " ID----> " << otherCustomer.customerID << endl;
	return output;
}
//end operator<< 
