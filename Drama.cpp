#include "Drama.h"

Drama::Drama()
{
	this->type = 0;
	this->title = "";
	this->director = "";
	this->releaseYear = 0;
	this->stock = 0;
}

Drama::Drama(const char type, int stock, const string director, const string title, int releaseYear)
{
	this->type = type;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->releaseYear = releaseYear;
}

Drama::~Drama()
{
}

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

ostream& operator<<(ostream& output, Drama& Movie)
{
	output << "Title: " << Movie.title << " Release Year: " << Movie.releaseYear
		<< "\n" << "Director: " << Movie.director << " Type: " << Movie.type
		<< "\n" << "---> Stock: " << Movie.stock << endl;

	return output;
}
