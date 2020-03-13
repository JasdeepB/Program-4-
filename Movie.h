#ifndef Movie_h
#define Movie_h
#include <iostream>
#include <string>

using namespace std;

class Movie
{
public:
	Movie();
	Movie(char type, int stock, string director, string title, int releaseYear);
	virtual ~Movie();

	char getType() const;

	string getTitle() const;
	string getDirector() const;
	string getDetails() const;

	int getReleaseYear() const;
	int getStock() const;

	bool Return();
	bool Borrow();

	void addToStock(int amount);

	virtual bool operator ==(Movie& otherMovie) const;
	virtual bool operator !=(Movie& otherMovie) const;
	virtual bool operator >(Movie& otherMovie) const;
	virtual bool operator <(Movie& otherMovie) const;

protected:
	char type;
	string title;
	string director;
	int releaseYear;
	int stock;
	int m_Stock;
};
#endif // !Movie_h