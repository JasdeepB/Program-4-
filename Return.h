#ifndef Return_h
#define Return_h
#include "Transaction.h"

class Return : public Transaction
{
public:
	Return();
	Return(const int customerID, char type, const int releaseMonth, const int releaseYear, const string majorActorFirstName, const string majorActorLastName);//classic movie
	Return(const int customerID, char type, const string title, int releaseYear);//funny movie
	Return(const int customerID, char type, const string director, string title);//Drama movie
	virtual ostream& display(ostream& output);
private:
	string transactionType = "Return";
};
#endif // !Return_h