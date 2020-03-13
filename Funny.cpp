#include "Funny.h"

Funny::Funny()
{
	this->type = 0;
	this->title = "";
	this->director = "";
	this->releaseYear = 0;
	this->stock = 0;
}

Funny::Funny(const char type, int stock, const string director, const string title, int releaseYear)
{
	this->type = type;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->releaseYear = releaseYear;
}

Funny::~Funny()
{
}

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

ostream& operator<<(ostream& output, Funny& movie)
{
	output << "Title: " << movie.title << " Release Year: " << movie.releaseYear
		<< "\n" << "Director: " << movie.director << " Type: " << movie.type
		<< "\n" << "---> Stock: " << movie.stock << endl;

	return output;
}
