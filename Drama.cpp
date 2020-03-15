// ------------------------------------------------ Drama.cpp -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the implementation file for the Drama class, a derived class from Movie
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------
#include "Drama.h"

// Default Constructor
Drama::Drama()
{
	this->type = 0;
	this->title = "";
	this->director = "";
	this->releaseYear = 0;
	this->stock = 0;
}

//Overloaded Constructor
Drama::Drama(const char type, int stock, const string director, const string title, int releaseYear)
{
	this->type = type;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->releaseYear = releaseYear;
}

//Destructor
Drama::~Drama()
{
}


// -------------------------------- operator == --------------------------------
// Description
// operator ==: Checks for equality
// preconditions: Drama object
// postconditions: booleon return
// -----------------------------------------------------------------------------
bool Drama::operator==(Drama& otherMovie) const
{
	if (otherMovie.getTitle() == "")
	{
		return false;
	}
	else
	{
		if (this->director == otherMovie.getDirector() && this->title == otherMovie.getTitle())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
// end of oprerator ==

// -------------------------------- operator != --------------------------------
// Description
// operator !=: Checks for inequality
// preconditions: Drama object
// postconditions: booleon return
// -----------------------------------------------------------------------------
bool Drama::operator!=(Drama& otherMovie) const
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
// end of operator !=

// -------------------------------- operator > --------------------------------
// Description
// operator >: Check for greater precedence
// preconditions: Drama object
// postconditions: booleon return type
// -----------------------------------------------------------------------------
bool Drama::operator>(Drama& otherMovie) const
{
	if (otherMovie.getTitle() == "")
	{
		return false;
	}
	else
	{
		// Compares by director's name, then Title
		if (this->director != otherMovie.getDirector())
		{
			if (this->director > otherMovie.getDirector())
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
			if (this->title > otherMovie.getTitle())
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
// operator >: Check for lesser precedence
// preconditions: Drama object
// postconditions: booleon return type
// -----------------------------------------------------------------------------
bool Drama::operator<(Drama& otherMovie) const
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

// -------------------------------- operator << --------------------------------
// Description
// operator <<: Prints the drama movie contents to the console
// preconditions: Drama object, and ostream object
// postconditions: ostream returned
// -----------------------------------------------------------------------------
ostream& operator<<(ostream& output, Drama& Movie)
{
	output << "Title: " << Movie.title << " Release Year: " << Movie.releaseYear
		<< "\n" << "Director: " << Movie.director << " Type: " << Movie.type
		<< "\n" << "---> Stock: " << Movie.stock << endl;

	return output;
}
// end of operator <<
