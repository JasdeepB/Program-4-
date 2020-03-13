#include "Movie.h"
#ifndef Classic_h
#define Classic_h

class Classic :	public Movie
{
public:
	Classic();
	Classic(const char type, int stock, const string director, const string title, const string majorActorFirstName, const string majorActorLastName, int releaseMonth, int releaseYear);
	virtual ~Classic();

	string getMajorActorFirstName() const;
	string getMajorActorLastName() const;
	int getReleaseMonth() const;


	friend ostream& operator << (ostream& output, Classic* movie);

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