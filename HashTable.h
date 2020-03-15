// ------------------------------------------------ hashTable.h -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the header file for the hashTable class. it uses an array and linked list to store values.
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------
#ifndef HashTable_HashTable_H
#define HashTable_HashTable_H
#include<iostream>
#include "Customer.h"

using namespace std;


class HashTable
{
public:
	//constructors and destructor
	HashTable();
	~HashTable();

	//ADT functions
	bool insert( Customer *cust);
	bool retrieve(int key, Customer *&holder);
	bool contains(Customer *cust);
	bool contains(int key);
	void clear();

private:

	int hash(int key);
	//node for linked list
	struct Node {
		Node(Customer cust, Node *nxt = nullptr) {
			data = cust;
			this->next = nxt;
		}
		Customer data;
		Node *next = nullptr;
	};

	int size;
	int capacity;
	Node **table;
};
#endif