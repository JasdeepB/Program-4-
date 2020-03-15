// ------------------------------------------------ Movie.cpp -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the implementation file for Movie. Movie is also the base class for the three types of  movies Funny, Drama, and Classic
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------

#include "Movie.h"

//Defualt Constructor
Movie::Movie()
{
	this->type = 0;
	this->title = "";
	this->director = "";
	this->releaseYear = 0;
	this->stock = 0;
	this->m_Stock = 0;
}

//Overloaded Constructor
Movie::Movie(char type, int stock, string director, string title, int releaseYear)
{
	this->type = type;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->releaseYear = releaseYear;
}

//Destructor
Movie::~Movie()
{
}

// -------------------------------- getType() --------------------------------
// Description
// getType(): Gets the type of movie
// preconditions: none
// postconditions: none
// -----------------------------------------------------------------------------
char Movie::getType() const
{
	return this->type;
}
//end of getType()

// -------------------------------- getTitle() --------------------------------
// Description
// getTitle(): Gets the title of the movie
// preconditions: none
// postconditions: none
// -----------------------------------------------------------------------------
string Movie::getTitle() const
{
	return this->title;
}
//end of getTitle()

// -------------------------------- getDirector() --------------------------------
// Description
// getDirector(): Gets the movies director
// preconditions: none
// postconditions: none
// -----------------------------------------------------------------------------
string Movie::getDirector() const
{
	return this->director;
}
//end of getDirector()

// -------------------------------- getDetails() --------------------------------
// Description
// getDetails(): Gets the title and director of the movie
// preconditions: none
// postconditions: none
// -----------------------------------------------------------------------------
string Movie::getDetails() const
{
	return "Title: " + this->title + " by " + this->director;
}
//end of getDetails

// -------------------------------- getReleaseYear() --------------------------------
// Description
// getReleaseYear(): Gets the release year of the movie
// preconditions: none
// postconditions: none
// -----------------------------------------------------------------------------
int Movie::getReleaseYear() const
{
	return this->releaseYear;
}
//end of getReleaseYear()

// -------------------------------- getStock() --------------------------------
// Description
// getStock(): Gets the current stock of the movie
// preconditions: none
// postconditions: none
// -----------------------------------------------------------------------------
int Movie::getStock() const
{
	return this->stock;
}
//end of getStock()

// -------------------------------- Return() --------------------------------
// Description
// Return(): Determines if a movie is eligible for return and increases the stock
// preconditions: none
// postconditions: none
// -----------------------------------------------------------------------------
bool Movie::Return()
{
	if (this->stock < this->m_Stock)
	{
		this->stock++;
		return true;
	}
	else
	{
		cout << "\nThis movie did not come from this store, so you can't return it" << endl;
		return false;
	}
}
// end of Return()

// -------------------------------- Borrow() --------------------------------
// Description
// Borrow(): Determines if a movie is eligible to be borrowed and reduces the stock
// preconditions: none
// postconditions: none
// -----------------------------------------------------------------------------
bool Movie::Borrow()
{
	if (!(this->stock <= 0))
	{
		this->stock--;
		return true;
	}
	else
	{
		cout << "\n" << this->title + " by " + this->director + " is currently out of stock\n";
		return false;
	}
}
//end of Borrow()

// -------------------------------- addToStock() --------------------------------
// Description
// addToStock(): Updates the movies stock based on a value
// preconditions: an amount
// postconditions: updated stock
// -----------------------------------------------------------------------------
void Movie::addToStock(int amount)
{
	//this->stock += amount;
}
//end of addToStock()

// -------------------------------- operator == --------------------------------
// Description
// operator ==: Checks for equality
// preconditions: Movie object
// postconditions: booleon return
// -----------------------------------------------------------------------------
bool Movie::operator==(Movie& otherMovie) const
{
	if (otherMovie.getTitle() == "")
	{
		return false;
	}
	else
	{
		if (this->title == otherMovie.getTitle() && this->releaseYear == otherMovie.getReleaseYear())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
//end of operator ==

// -------------------------------- operator != --------------------------------
// Description
// operator !=: Checks for inequality
// preconditions: Movie object
// postconditions: booleon return
// -----------------------------------------------------------------------------
bool Movie::operator!=(Movie& otherMovie) const
{
	if (otherMovie.getTitle() == "")
	{
		return false;
	}
	else
	{
		return !(*this == otherMovie);
	}
}
//end of operator !=

// -------------------------------- operator > --------------------------------
// Description
// operator >: Check for greater precedence
// preconditions: Movie object
// postconditions: booleon return type
// -----------------------------------------------------------------------------
bool Movie::operator>(Movie& otherMovie) const
{
	if (otherMovie.getTitle() == "")
	{
		return false;
	}
	else
	{

		if (this->title != otherMovie.getTitle())
		{
			if (this->title > otherMovie.getTitle())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (releaseYear > otherMovie.getReleaseYear())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}
// end of operator >

// -------------------------------- operator < --------------------------------
// Description
// operator <: Check for lesser precedence
// preconditions: Movie object
// postconditions: booleon return type
// -----------------------------------------------------------------------------
bool Movie::operator<(Movie& otherMovie) const
{
	if (otherMovie.getTitle() == "")
	{
		return false;
	}
	else
	{
		return !(*this > otherMovie);
	}
}
//end of operator <