#include "Movie.h"
#ifndef Drama_h
#define Drama_h

class Drama : public Movie
{
public:
	Drama();
	Drama(const char type, int stock, const string director, const string title, int releaseYear);
	virtual ~Drama();

	friend ostream& operator <<(ostream& output, Drama& Movie);

	bool operator ==(Drama& otherMovie) const;
	bool operator !=(Drama& otherMovie) const;
	bool operator >(Drama& otherMovie) const;
	bool operator <(Drama& otherMovie) const;
};

#endif // !Drama_h