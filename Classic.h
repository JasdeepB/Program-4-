// ------------------------------------------------ Classic.h -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the header file for the Classic class. Inherits from movie
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------
#include "Movie.h"
#ifndef Classic_h
#define Classic_h

class Classic :	public Movie
{
public:
	//constructors and destructors
	Classic();
	Classic(const char type, int stock, const string director, const string title, const string majorActorFirstName, const string majorActorLastName, int releaseMonth, int releaseYear);
	virtual ~Classic();

	//getters 
	string getMajorActorFirstName() const;
	string getMajorActorLastName() const;
	int getReleaseMonth() const;

	//operators
	friend ostream& operator << (ostream& output, Classic& movie);
	bool operator ==(Classic& otherMovie) const;
	bool operator !=(Classic& otherMovie) const;
	bool operator >(Classic& otherMovie) const;
	bool operator <(Classic& otherMovie) const;

private:
	string majorActorFirstName;
	string majorActorLastName;
	int releaseMonth;
};

#endif // !Classic_h