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
	//Return test;
	//Borrow test2;
};
#endif // !Customer_h