#ifndef Transaction_h
#define Transaction_h
#include <iostream>
#include <string>

using namespace std;

class Transaction
{
public:
	Transaction();
	virtual ~Transaction();

	char getType() const;
	int getCustomerID() const;

	friend ostream& operator <<(ostream& output, Transaction& t);
	virtual void display();

protected: 
	char type;
	char format = 'D';
	string title;
	string director;
	string majorActorFirstName;
	string majorActorLastName;
	int releaseMonth;
	int releaseYear;
	int customerID;
};
#endif // !Transaction_h