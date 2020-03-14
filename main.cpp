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
	im.buildMovies(movies);
	im.buildCustomers(customers);
	im.processTransaction(commands);
	im.showAllInventory();

	cout << "does the following customer exist in the file?";

}