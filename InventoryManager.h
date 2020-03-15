// ------------------------------------------------ inventoryManager.h -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the header file for the Inventory manager class.
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------
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
	//constructor and destructor
	InventoryManager();
	~InventoryManager();

	//buildm movie objects, populates movie bst
	bool buildMovies(ifstream& moviesData);
	//builds customer objects, populates customer hashtable
	bool buildCustomers(ifstream& customersData);
	//process transactions
	bool processTransaction(ifstream& commandsFile);
	//shows history of store
	void showAllInventory();

private:
	BST<Funny> funnyMoviesBST;
	BST<Drama> dramaMoviesBST;
	BST<Classic> classicMoviesBST;
	HashTable customerTable;
};
#endif // !InventoryManager_h