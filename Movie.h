// ------------------------------------------------ Movie.h -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the header file for the Movie class.
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------
#ifndef Movie_h
#define Movie_h
#include <iostream>
#include <string>

using namespace std;

class Movie
{
public:
	//constructors and destructors
	Movie();
	Movie(char type, int stock, string director, string title, int releaseYear);
	virtual ~Movie();
	//getters 
	char getType() const;
	string getTitle() const;
	string getDirector() const;
	string getDetails() const;
	int getReleaseYear() const;
	int getStock() const;
	//specific functions to return and borrow movies
	bool Return();
	bool Borrow();

	//stub
	void addToStock(int amount);
	//operators
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