#include "Movie.h"

Movie::Movie()
{
	this->type = 0;
	this->title = "";
	this->director = "";
	this->releaseYear = 0;
	this->stock = 0;
	this->m_Stock = 0;
}

Movie::Movie(char type, int stock, string director, string title, int releaseYear)
{
	this->type = type;
	this->stock = stock;
	this->director = director;
	this->title = title;
	this->releaseYear = releaseYear;
}

Movie::~Movie()
{
}

char Movie::getType() const
{
	return this->type;
}

string Movie::getTitle() const
{
	return this->title;
}

string Movie::getDirector() const
{
	return this->director;
}

string Movie::getDetails() const
{
	return "Title: " + this->title + " by " + this->director;
}

int Movie::getReleaseYear() const
{
	return this->releaseYear;
}

int Movie::getStock() const
{
	return this->stock;
}

bool Movie::Return()
{
	if (this->stock < this->m_Stock)
	{
		this->stock++;
		return true;
	}
	else
	{
		cout << "This movie did not come from this store, so you can't return it" << endl;
		return false;
	}
}

bool Movie::Borrow()
{
	if (!(this->stock <= 0))
	{
		this->stock--;
		return true;
	}
	else
	{
		cout << this->title + " by " + this->director + " is currently out of stock";
		return false;
	}
}

void Movie::addToStock(int amount)
{
	//this->stock += amount;
}

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
