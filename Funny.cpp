// ------------------------------------------------ Funny.cpp -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the implementation file for the Funny class, a derived class from Movie
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------

#include "Funny.h"

//Default Constructor
Funny::Funny()
{
	this->type = 0;
	this->title = "";
	this->director = "";
	this->releaseYear = 0;
	this->stock = 0;
}

//Overloaded Constructor
Funny::Funny(const char type, int stock, const string director, const string title, int releaseYear)
{
	this->type = type;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->releaseYear = releaseYear;
}

//Destructor
Funny::~Funny()
{
}

// -------------------------------- operator == --------------------------------
// Description
// operator ==: Checks for equality
// preconditions: Funny object
// postconditions: booleon return
// -----------------------------------------------------------------------------
bool Funny::operator==(Funny& otherMovie) const
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
// preconditions: Funny object
// postconditions: booleon return
// -----------------------------------------------------------------------------
bool Funny::operator!=(Funny& otherMovie) const
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
// preconditions: Funny object
// postconditions: booleon return type
// -----------------------------------------------------------------------------
bool Funny::operator>(Funny& otherMovie) const
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
// preconditions: Funny object
// postconditions: booleon return type
// -----------------------------------------------------------------------------
bool Funny::operator<(Funny& otherMovie) const
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
// end of operator <

// -------------------------------- operator << --------------------------------
// Description
// operator <<: Prints the funny movie contents to the console
// preconditions: Funny object, and ostream object
// postconditions: ostream returned
// -----------------------------------------------------------------------------
ostream& operator<<(ostream& output, Funny& movie)
{
	output << "Title: " << movie.title << " Release Year: " << movie.releaseYear
		<< "\n" << "Director: " << movie.director << " Type: " << movie.type
		<< "\n" << "---> Stock: " << movie.stock << endl;

	return output;
}
// end of operator <<