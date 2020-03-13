#include "Movie.h"
#ifndef Funny_h
#define Funny_h

class Funny : public Movie
{
public:
	Funny();
	Funny(const char type, int stock, const string director, const string title, int releaseYear);
	virtual ~Funny();

	friend ostream& operator <<(ostream& output, Funny& movie);

	bool operator ==(Funny& otherMovie) const;
	bool operator !=(Funny& otherMovie) const;
	bool operator >(Funny& otherMovie) const;
	bool operator <(Funny& otherMovie) const;
};

#endif // !Funny_h