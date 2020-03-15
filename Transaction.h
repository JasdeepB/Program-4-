// ------------------------------------------------ Transaction.h -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the header file for the Transaction class.
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------
#ifndef Transaction_h
#define Transaction_h
#include <iostream>
#include <string>

using namespace std;

class Transaction
{
public:
	//constructors and destructors
	Transaction();
	virtual ~Transaction();

	//getters
	char getType() const;
	int getCustomerID() const;

	friend ostream& operator <<(ostream& output, Transaction& t);
	virtual void display();

protected: 
	//data fields to cover all genres
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