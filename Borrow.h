#ifndef Borrow_h
#define Borrow_h
#include "Transaction.h"

class Borrow : public Transaction
{
public:
	Borrow();
	Borrow(const int customerID,
		char type,
		const string title,
		const string director,
		int releaseYear,
		const string majorActorFirstName = "",
		const string majorActorLastName = "",
		const int releaseMonth = 0);

	virtual ostream& display(ostream &output);
private:
	string transactionType = "Borrow";
};
#endif // !Borrow_h
