// ------------------------------------------------ Return.h -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the header file for the Return class. It inherits from the Transaction class;
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------
#ifndef Return_h
#define Return_h
#include "Transaction.h"

class Return : public Transaction
{
public:
	//constructors and destructors
	Return();
	Return(const string t, const int customerID, char type, const int releaseMonth, const int releaseYear, const string majorActorFirstName, const string majorActorLastName); //Classic movie
	Return(const int customerID, char type, const string title, int releaseYear); //Funny movie
	Return(const int customerID, char type, const string director, string title); //Drama movie
	virtual void display();
private:
	string transactionType = "Return";
};
#endif // !Return_h