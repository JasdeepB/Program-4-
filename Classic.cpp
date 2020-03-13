#include "Classic.h"

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

Classic::Classic(const char type, int stock, const string director, const string title, const string majorActorFirstName, const string majorActorLastName, int releaseMonth, int releaseYear)
{
	this->type = type;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->majorActorFirstName = majorActorFirstName;
	this->majorActorFirstName = majorActorLastName;
	this->releaseYear = releaseYear;
	this->releaseMonth = releaseMonth;
}

Classic::~Classic()
{
}

string Classic::getMajorActorFirstName() const
{
	return this->majorActorFirstName;
}

string Classic::getMajorActorLastName() const
{
	return this->majorActorLastName;
}

int Classic::getReleaseMonth() const
{
	return this->releaseMonth;
}

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

ostream& operator<<(ostream& output, Classic* movie)
{
	output << "Release date: " << movie->releaseMonth << " - " << movie->releaseYear << "Major Actor: " << movie->majorActorFirstName << " " << movie->majorActorLastName
		<< "\n" << "Title: " << movie->title << " Director: " << movie->director << " Type: " << movie->type
		<< "\n" << "Stock ----> " << movie->stock << endl;
	return output;
}
