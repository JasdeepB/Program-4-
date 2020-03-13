#ifndef Customer_h
#define Customer_h
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer
{
	Customer();
	Customer(int ID, string firstName, string lastName);
	~Customer();

	int& getCustomerID();

	void addTransaction(string transactionInfo); 
	void showAllTransactions(); 

	bool operator==(const Customer& otherCustomer) const;
	bool operator!=(const Customer& otherCustomer) const;

	friend ostream& operator <<(ostream& output, Customer& otherCustomer);

private:
	int customerID; 
	string firstName;
	string lastName; 
	vector<string> transactions;
	//friend class HashTable;
};
#endif // !Customer_h