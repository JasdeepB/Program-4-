#ifndef HashTable_HashTable_H
#define HashTable_HashTable_H
#include<iostream>
#include "Customer.h"

using namespace std;


class HashTable
{
public:
	HashTable();
	~HashTable();
	bool insert( Customer *cust);
	//bool remove(int key);
	bool retrieve(int key, Customer *&holder);
	bool contains(Customer *cust);
	bool contains(int key);
	void clear();

private:
	int hash(int key);
	struct Node {
		Node(Customer cust, Node *nxt = nullptr) {
			data = cust;
			this->next = nxt;
		}
		Customer data;
		Node *next = nullptr;
	};
	static const int DEFAULT_TABLE_SIZE = 127;
	Node **table;

};
#endif HashTable_HashTable_H