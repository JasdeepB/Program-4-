#ifndef InventoryManager_h
#define InventoryManager_h
#include <iostream>
#include <fstream>
#include <string>
#include "Movie.h"
#include "Customer.h"

using namespace std;

class InventoryManager
{
public:
	InventoryManager();
	~InventoryManager();

	bool buildMovies(ifstream& moviesData);
	bool buildCustomers(ifstream& customersData);
	bool processTransaction(ifstream& commandsFile);

private:
	//Trees
	//HashTable
};
#endif // !InventoryManager_h