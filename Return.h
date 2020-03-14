#ifndef Return_h
#define Return_h
#include "Transaction.h"

class Return : public Transaction
{
public:
	Return();
	Return(const int customerID, 
		char type,
		const string title,
		const string director,
		int releaseYear,
		const string majorActorFirstName = "",
		const string majorActorLastName = "",
		const int releaseMonth = 0);
	virtual ostream& display(ostream& output);
private:
	string transactionType = "Return";
};
#endif // !Return_h