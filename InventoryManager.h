#ifndef InventoryManager_h
#define InventoryManager_h
#include <iostream>
#include <fstream>
#include <string>
#include "Movie.h"
#include "Funny.h"
#include "Drama.h"
#include "Classic.h"
#include "Customer.h"
#include "BST.h"
#include "HashTable.h"
#include "Transaction.h"

using namespace std;

class InventoryManager
{
public:
	InventoryManager();
	~InventoryManager();

	bool buildMovies(ifstream& moviesData);
	bool buildCustomers(ifstream& customersData);
	bool processTransaction(ifstream& commandsFile);
	void showAllInventory();

private:
	BST<Funny> funnyMoviesBST;
	BST<Drama> dramaMoviesBST;
	BST<Classic> classicMoviesBST;
	HashTable customerTable;
};
#endif // !InventoryManager_h