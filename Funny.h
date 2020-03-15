// ------------------------------------------------ Funny.h -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the header file for the Funny class. it inherits from movie.
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------
#include "Movie.h"
#ifndef Funny_h
#define Funny_h

class Funny : public Movie
{
public:
	//constructors and destructors
	Funny();
	Funny(const char type, int stock, const string director, const string title, int releaseYear);
	virtual ~Funny();

	//operators
	friend ostream& operator <<(ostream& output, Funny& movie);
	bool operator ==(Funny& otherMovie) const;
	bool operator !=(Funny& otherMovie) const;
	bool operator >(Funny& otherMovie) const;
	bool operator <(Funny& otherMovie) const;
};

#endif // !Funny_h