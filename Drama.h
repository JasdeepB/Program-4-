// ------------------------------------------------Drama.h -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the header file for the Drama class. Inherits from movie
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------
#include "Movie.h"
#ifndef Drama_h
#define Drama_h

class Drama : public Movie
{
public:
	//constructors
	Drama();
	Drama(const char type, int stock, const string director, const string title, int releaseYear);
	virtual ~Drama();
	//operators
	friend ostream& operator <<(ostream& output, Drama& Movie);
	bool operator ==(Drama& otherMovie) const;
	bool operator !=(Drama& otherMovie) const;
	bool operator >(Drama& otherMovie) const;
	bool operator <(Drama& otherMovie) const;
};

#endif // !Drama_h