// ------------------------------------------------ Borrow.h -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the header file for the borrow class. This is a subclass of transaction
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------
#ifndef Borrow_h
#define Borrow_h
#include "Transaction.h"

class Borrow : public Transaction
{
public:
	//constructors, 
	Borrow();
	Borrow(const int customerID, char Type, const int releaseMonth, const int releaseYear, const string majorActorFirstName, const string majorActorLastName);//classic movie
	Borrow(const int customerID, char type, const string title, int releaseYear);//funny movie
	Borrow(const int customerID, char type, const string director, string title);//Drama movie

	virtual void display();
private:
	string transactionType = "Borrow";
};
#endif // !Borrow_h
