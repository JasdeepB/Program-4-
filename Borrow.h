#ifndef Borrow_h
#define Borrow_h
#include "Transaction.h"

class Borrow : public Transaction
{
public:
	Borrow();
	Borrow(const int customerID, char Type, const int releaseMonth, const int releaseYear, const string majorActorFirstName, const string majorActorLastName);//classic movie
	Borrow(const int customerID, char type, const string title, int releaseYear);//funny movie
	Borrow(const int customerID, char type, const string director, string title);//Drama movie

	virtual ostream& display(ostream &output);
private:
	string transactionType = "Borrow";
};
#endif // !Borrow_h
