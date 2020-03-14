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
bool InventoryManager::buildCustomers(ifstream& customersData)
{	
	bool b = false;
	int idNumber;
	string first, last;
	if (!customersData)
	{
		cout << "Could not open the customer data file!" << endl;
		return false;
	}
	while(customersData){

		customersData >> idNumber >> last >> first;

		Customer *newCust = new Customer(idNumber, first, last);
		b = customerTable.insert(idNumber, newCust);
	}
	return b;
}
bool InventoryManager::processTransaction(ifstream & commandsFile)
{
	char trns, dvd, genre, comma;
	int id, month, year;
	string director, title, majorActorF, majorActorL;
	if (!commandsFile)
	{
		cout << "Could not open the command data file!" << endl;
		return false;
	}
	while (commandsFile) {
		commandsFile >> trns;
		if (trns == 'B' | trns == 'R') {
			commandsFile >> id >> dvd >> genre;
			if (genre == 'F') {
				getline(commandsFile, title, ',');
				commandsFile >> year;

			}
			else if (genre == 'D') {
				getline(commandsFile, director, ',');
				getline(commandsFile, title, ',');
			
			}
			else if(genre == 'C') {
				commandsFile >> month >> year;
				commandsFile >> majorActorF >> majorActorL;
			}
			else {
				cout << "Invalid Genre Type" << endl;
			}

		}
		else if (trns == 'H') {
			commandsFile >> id;
			Customer *myCust = customerTable.retrieve(id);
			if (myCust != nullptr) {
				myCust->showAllTransactions();
			}
			else {
				cout << "Customer does not exist" << endl;
			}
		}
		else if (trns == 'I') {
			showAllInventory();
		}
		else {
			cout << trns << " is an invalid command." << endl;
		}
	}

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
	cout << "\n===================== CURRENT INVENTORY =====================\n\n";
	cout << "===================== All Comedy Movies =====================\n";
	funnyMoviesBST.display();
	cout << "=====================  All Drama Movies  ====================\n";
	dramaMoviesBST.display();
	cout << "===================== All Classic Movies ====================";
	classicMoviesBST.display();
	cout << "==================   END OF ALL INVENTORY   =================";
}
