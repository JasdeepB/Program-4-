// ------------------------------------------------ Main.cpp -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the main entry point for the program. From here the movies, and customer data structures will be filled, and
//the transaction will be executed
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "InventoryManager.h"

using namespace std;

int main()
{
	// ifstream object created and loaded
	ifstream movies("data4movies.txt");
	ifstream customers("data4customers.txt");
	ifstream commands("data4commands.txt");

	// Our Inventory Manager object
	InventoryManager im;
	cout << "******************* BUILDING MOVIE LIBRARY *********************\n";
	im.buildMovies(movies);

	cout << "\n******************* BUILDING CUSTOMER TABLE ******************\n";
	im.buildCustomers(customers);

	cout << "\n**************** NOW PROCESSESING TRANSACTIONS ***************\n";
	im.processTransaction(commands);

	cout << "\n*********** PROCESSESING COMPLETED - SHOW INVENTORY **********\n";
	im.showAllInventory();
}