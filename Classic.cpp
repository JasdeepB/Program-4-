#include "Classic.h"

//Constructor
Classic::Classic()
{
	this->type = 0;
	this->stock = 0;
	this->director = "";
	this->title = "";
	this->majorActorFirstName = "";
	this->majorActorLastName = "";
	this->releaseMonth = 0;
	this->releaseYear = 0;
}

// Full constructor
Classic::Classic(const char type, int stock, const string director, const string title, const string majorActorFirstName, const string majorActorLastName, int releaseMonth, int releaseYear)
{
	this->type = type;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->majorActorFirstName = majorActorFirstName;
	this->majorActorLastName = majorActorLastName;
	this->releaseYear = releaseYear;
	this->releaseMonth = releaseMonth;
}
//Destructor
Classic::~Classic()
{
}
// -------------------------------- getMajorActorFirstName() --------------------------------
// Description
// getMajorActorFirstName: returns a string containing actotrs first name
// preconditions:valid classic object
// postconditions: string containing first name
// -----------------------------------------------------------------------------
string Classic::getMajorActorFirstName() const
{
	return this->majorActorFirstName;
}
//end getMajorActorFirstName

// -------------------------------- getMajorActorLasttName() ---------------------
// Description
// getMajorActorLastName: returns a string containing actotrs last name
// preconditions:valid classic object
// postconditions: string containing last name
// -----------------------------------------------------------------------------
string Classic::getMajorActorLastName() const
{
	return this->majorActorLastName;
}
//end getMajorActorLastName

// -------------------------------- getReleaseMonth() ---------------------
// Description
// getReleaseMonth(): returns an int containing the release month
// preconditions:valid classic object
// postconditions: int containing release month
// -----------------------------------------------------------------------------
int Classic::getReleaseMonth() const
{
	return this->releaseMonth;
}
//end getReleaseMonth


// -------------------------------- ==operator ---------------------
// Description
//  ==operator: compares two classic objects and returns true if they are equal
// preconditions:two valid classic objects
// postconditions: equality of two classic objects is assessed
// -----------------------------------------------------------------------------
bool Classic::operator==(Classic& otherMovie) const
{
	if (otherMovie.getReleaseMonth() == 0)
	{
		return false;
	}
	else
	{
		return (this->majorActorFirstName == otherMovie.getMajorActorFirstName()
			&& this->majorActorLastName == otherMovie.getMajorActorLastName()
			&& this->releaseMonth == otherMovie.getReleaseMonth()
			&& this->releaseYear == otherMovie.getReleaseYear());
	}
}
//end == operator

// -------------------------------- operator != ---------------------
// Description
// operator !=: compares two classic objects and returns false if they are equal
// preconditions:two valid classic objects
// postconditions: equality of two classic objects is assessed
// -----------------------------------------------------------------------------
bool Classic::operator!=(Classic& otherMovie) const
{
	if (otherMovie.getReleaseMonth() == 0)
	{
		return false;
	}
	else
	{
		return !(*this == otherMovie);
	}
}
//end operator!=

// -------------------------------- >operator ---------------------
// Description
//  operator >: compares two classic objects and returns true if the calling object
//is greater
// preconditions:two valid classic objects
// postconditions: whether one movie object is greater than the other 
// -----------------------------------------------------------------------------
bool Classic::operator>(Classic& otherMovie) const
{
	if (otherMovie.getReleaseMonth() == 0)
	{
		return false;
	}
	else
	{
		if (this->releaseYear != otherMovie.getReleaseYear())
		{
			if (this->releaseYear > otherMovie.getReleaseYear())
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
			if (this->releaseMonth > otherMovie.getReleaseMonth())
			{
				return true;
			}
			else if (this->releaseMonth == otherMovie.getReleaseMonth())
			{
				if (this->majorActorFirstName > otherMovie.getMajorActorFirstName())
				{
					return true;
				}
				else if (this->majorActorFirstName == otherMovie.getMajorActorFirstName())
 				{
					if (this->majorActorLastName > otherMovie.getMajorActorLastName())
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
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
}
//end >operator

// -------------------------------- <operator ---------------------
// Description
//  operator >: compares two classic objects and returns true if the calling object
//is less than
// preconditions:two valid classic objects
// postconditions: whether one movie object is less than than the other 
// --------------------------------------------------------------------------
bool Classic::operator<(Classic& otherMovie) const
{
	if (otherMovie.getReleaseMonth() == 0)
	{
		return false;
	}
	else
	{
		return !(*this > otherMovie);
	}
}
//end operator<

// -------------------------------- <<operator ---------------------
// Description
//  operator <: compares two classic objects and returns true if the calling object
//is greater
// preconditions:two valid classic objects
// postconditions: whether one movie object is greater than the other 
// --------------------------------------------------------------------------
ostream& operator<<(ostream& output, Classic& movie)
{
	output << "\nRelease date: " << movie.releaseMonth << " - " << movie.releaseYear
		<< "\nMajor Actor: " << movie.majorActorFirstName << " " << movie.majorActorLastName
		<< "\n" << "Title: " << movie.title
		<< "\nDirector: " << movie.director 
		<< "\nType: " << movie.type
		<< "\n" << "Stock ----> " << movie.stock << endl;
	return output;
}
