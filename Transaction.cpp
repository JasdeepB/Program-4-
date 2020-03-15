// ------------------------------------------------ Transaction.cpp -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the implementation file for the Transaction class that will act as the base class for Borrow and Return
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------

#include "Transaction.h"

//Default Constructor
Transaction::Transaction()
{
	this->type = 0;
	this->title = "";
	this->director = "";
	this->majorActorFirstName = "";
	this->majorActorLastName = "";
	this->releaseMonth = 0;
	this->releaseYear = 0;
	this->customerID = 0;
}

// -------------------------------- operator << --------------------------------
// Description
// operator <<: prints out the transaction
// preconditions: none
// postconditions: none
// -----------------------------------------------------------------------------
ostream& operator <<(ostream& output, Transaction& t)
{
	return output;
}
// end of oprerator <<

// Destructor
Transaction::~Transaction()
{
}

// -------------------------------- getCustomerID() --------------------------------
// Description
// getCustomerID: gets the objects customer ID
// preconditions: none
// postconditions: none
// -----------------------------------------------------------------------------
int Transaction::getCustomerID() const
{
	return this->customerID;
}
// end of getCustomerID()


// -------------------------------- display --------------------------------
// Description
// display: prints out the transaction
// preconditions: none
// postconditions: none
// -----------------------------------------------------------------------------
void Transaction::display()
{
	if (type == 'C')
	{
		cout << "Customer: " << customerID
			<< "\n" << "Borrowed: " << releaseMonth << " " << releaseYear << " " << majorActorFirstName << " " << majorActorLastName << endl;
	}
	else
	{
		cout << "Customer: " << customerID
			<< "\n" << "Borrowed: " << title << endl;
	}
}
// end of display()

// -------------------------------- getType() --------------------------------
// Description
// getType: gets the objects movie type
// preconditions: none
// postconditions: none
// -----------------------------------------------------------------------------
char Transaction::getType() const
{
	return this->type;
}
// end of getType()