#include "InventoryManager.h"

InventoryManager::InventoryManager()
{
	this->funnyMoviesBST;
	this->dramaMoviesBST;
	this->classicMoviesBST;
}

InventoryManager::~InventoryManager()
{
}

bool InventoryManager::buildMovies(ifstream& moviesData)
{
	char type, comma;
	int stock, releaseMonth, releaseYear;
	string director, title, majorActorFirstName, majorActorLastName;
	
	if (!moviesData)
	{
		cout << "Could not open the movies data file!" << endl;
		return false;
	}

	while (true)
	{
		if (moviesData.eof())
		{
			break;
		}

		moviesData >> type >> comma;

		if (type == 'F' || type == 'D')
		{
			moviesData >> stock >> comma;
			getline(moviesData, director, ',');
			getline(moviesData, title, ',');
			moviesData >> releaseYear;

			if (type == 'F')
			{
				Funny f(type, stock, director, title, releaseYear);
				funnyMoviesBST.insert(f);
			}
			else
			{
				Drama d(type, stock, director, title, releaseYear);
				dramaMoviesBST.insert(d);
			}
			
		}
		else if (type == 'C')
		{
			moviesData >> stock >> comma;
			getline(moviesData, director, ',');
			getline(moviesData, title, ',');
			moviesData >> majorActorFirstName >> majorActorLastName >> releaseMonth >> releaseYear;

			Classic c(type, stock, director, title, majorActorFirstName, majorActorLastName, releaseMonth, releaseYear);
			classicMoviesBST.insert(c);
		}
		else
		{
			string invalidType;
			getline(moviesData, invalidType);
			cout << "Movie type: " << type << " is not valid" << endl;
		}
	}
	return true;
}

void InventoryManager::showAllInventory()
{
	cout << "===================== CURRENT INVENTORY =====================\n";
	cout << "===================== All Comedy Movies =====================\n";
	funnyMoviesBST.display();
	cout << "=====================  All Drama Movies  ====================\n";
	dramaMoviesBST.display();
	cout << "===================== All Classic Movies ====================";
	classicMoviesBST.display();
	cout << "==================   END OF ALL INVENTORY   =================";
}
