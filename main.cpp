#include <iostream>
#include <string>
#include "InventoryManager.h"

using namespace std;

int main()
{
	ifstream movies("data4movies.txt");
	ifstream customers("data4customers.txt");
	ifstream commands("data4commands.txt");

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