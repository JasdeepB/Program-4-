#include "InventoryManager.h"
//constructor
InventoryManager::InventoryManager()
{
	this->funnyMoviesBST;
	this->dramaMoviesBST;
	this->classicMoviesBST;
	this->customerTable;
}
//end constructor

//default constructor
InventoryManager::~InventoryManager()
{
}
//end constructor

// ------------------------------------buildCustomers---------------------------------------
// Description
// buildCustomers: Creates customer objects and populates customer hashtable with them
// preconditions: empty hash table, and valid filestream
// postconditions: populated hashtables, filestream eof
//
// -----------------------------------------------------------------------------
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
		b = customerTable.insert(newCust);
	}
	return b;
}
//end buildCustomers

// ------------------------------------processTransaction---------------------------------------
// Description
// processTransactions: runs through the transactions data file and updates inventory and customer
// preconditions: A valid input filestream object
// postconditions: filestream is eof and inventory in BSTs and Hashtables have changed to reflect the commands
//
// -----------------------------------------------------------------------------
bool InventoryManager::processTransaction(ifstream& commandsFile)
{
	char trns, dvd, genre, comma;
	int id, month, year;
	string director, title, majorActorF, majorActorL;
	Transaction t;
	
	if (!commandsFile)
	{
		cout << "Could not open the command data file!" << endl;
		return false;
	}
	while (commandsFile)
	{
		commandsFile >> trns;

		if (trns == 'B') 
		{
			commandsFile >> id >> dvd;
			if (dvd == 'D') 
			{
				commandsFile >> genre;
				if (genre == 'F' || genre == 'D' || genre == 'C')
				{
					if (genre == 'F') 
					{
						getline(commandsFile, title, ',');
						commandsFile >> year;
						t = Borrow(id, genre, title, year);
						Funny *f = nullptr;
						if (!funnyMoviesBST.retrieve(title, year, f)) 
						{
							cout << "Movie not in Inventory" << endl;
						}
						else
						{
							f->Borrow();
						}
					}
					else if (genre == 'D')
					{
						getline(commandsFile, director, ',');
						getline(commandsFile, title, ',');
						t = Borrow(id, genre, director, title);
						Drama *d = nullptr;
						//dramaMoviesBST.retrieve(director, title, d);
						if (!dramaMoviesBST.retrieve(director, title, d)) 
						{
							cout << "Movie not in Inventory" << endl;
						}
						else
						{
							d->Borrow();
						}
					}
					else if (genre == 'C')
					{
						commandsFile >> month >> year;
						commandsFile >> majorActorF >> majorActorL;
						t = Borrow(id, genre, month, year, majorActorF, majorActorL);
						Classic *c = nullptr;
						//classicMoviesBST.retrieve(majorActorF, majorActorL, month, year, c);
						//c->Borrow();
						if (!classicMoviesBST.retrieve(director, title, c)) {
							cout << "Movie not in Inventory" << endl;
						}
						else {
							c->Borrow();
						}

					}
					else
					{
						cout << "Invalid Genre Type" << endl;
					}
					Customer *cust = nullptr;
					customerTable.retrieve(id, cust);
					if (cust != nullptr) {
						cust->addTransaction(t);
					}
					else
					{
						cout << "Customer does not exist" << endl;
					}
				}
			}
			else 
			{
				cout << "invalid media type" << endl;
			}
		}
		else if (trns == 'R')
		{
			commandsFile >> id >> dvd >> genre;
			if (dvd == 'D') {
				commandsFile >> genre;
				if (genre == 'F' || genre == 'D' || genre == 'C')
				{
					if (genre == 'F')
					{
						getline(commandsFile, title, ',');
						commandsFile >> year;
						t = Return(id, genre, title, year);
						Funny *f = nullptr;
						//funnyMoviesBST.retrieve(title, year, f);
						//f->Return();
						if (!funnyMoviesBST.retrieve(title, year, f))
						{
							cout << "Movie not in Inventory" << endl;
						}
						else {
							f->Return();
						}
					}
					else if (genre == 'D')
					{
						getline(commandsFile, director, ',');
						getline(commandsFile, title, ',');
						t = Return(id, genre, director, title);
						Drama *d = nullptr;
						//dramaMoviesBST.retrieve(director, title, d);
						//d->Return();
						if (!dramaMoviesBST.retrieve(director, title, d)) {
							cout << "Movie not in Inventory" << endl;
						}
						else {
							d->Return();
						}

					}
					else if (genre == 'C')
					{
						commandsFile >> month >> year;
						commandsFile >> majorActorF >> majorActorL;
						t = Return(id, genre, month, year, majorActorF, majorActorL);
						Classic *c = nullptr;
						//classicMoviesBST.retrieve(majorActorF, majorActorL, month, year, c);
						//c->Return();
						if (!classicMoviesBST.retrieve(majorActorF, majorActorL, month, year, c)) 
						{
							cout << "Movie not in Inventory" << endl;
						}
						else 
						{
							c->Return();
						}

					}

					Customer *cust = nullptr;
					customerTable.retrieve(id, cust);

					if (cust != nullptr) 
					{
						cust->addTransaction(t);
					}
					else 
					{
						cout << "Customer does not exist" << endl;
					}
				}
				else
				{
					cout << "Invalid Genre Type" << endl;
				}
			}
			else
			{
				cout << "Invalid media type" << endl;
			}
		}
		else if (trns == 'H')
		{
			commandsFile >> id;
			Customer *myCust;
			customerTable.retrieve(id, myCust);

			if (myCust != nullptr) 
			{
				myCust->showAllTransactions();
			}
			else
			{
				cout << "Customer does not exist" << endl;
			}
		}
		else if (trns == 'I')
		{
			showAllInventory();
		}
		else
		{
			string s;
			getline(commandsFile, s);
			cout << trns << " is an invalid command." << endl;
		}
	}

}
//end processTransactions

// ------------------------------------buildMovies---------------------------------------
// Description
// buildMovies: creates movie objects and populates BST 
// preconditions: A valid input filestream object, and an empty BST
// postconditions: filestream is eof and BSTs populated with movies from filestream
//
// -----------------------------------------------------------------------------
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
//end buildMovies


// ------------------------------------showAllInventory---------------------------------------
// Description
// showAllInventory: prints out the contents of the movie BSTs
// preconditions: Populated BSTs
// postconditions: none
//
// -----------------------------------------------------------------------------
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
//end showAllInventory
