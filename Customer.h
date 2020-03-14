// ------------------------------------------------ Customer.h -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the header file for the customer class. it uses a vector to record the transaction of a customer.
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------
#ifndef Customer_h
#define Customer_h
#include <iostream>
#include <string>
#include <vector>
#include "Transaction.h"
#include "Return.h"
#include "Borrow.h"

using namespace std;

class Customer
{
public:
	Customer();
	Customer(int ID, string firstName, string lastName);
	~Customer();

	int getCustomerID();

	void addTransaction(Transaction t);
	void showAllTransactions(); 

	bool operator==(const Customer& otherCustomer) const;
	bool operator!=(const Customer& otherCustomer) const;

	friend ostream& operator <<(ostream& output, Customer& otherCustomer);

private:
	int customerID; 
	string firstName;
	string lastName; 
	vector<Transaction> transactions;
	friend class HashTable;
};
#endif // !Customer_h