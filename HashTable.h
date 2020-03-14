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
	bool insert(int key, Customer *cust);
	//bool remove(int key);
	Customer * retrieve(int key);
	bool contains(int key);
	void clear();

private:
	int hash(int key);
	struct Node {
		Customer *data;
		Node *next = nullptr;
	};
	static const int DEFAULT_TABLE_SIZE = 128;
	Node **table;

};
#endif HashTable_HashTable_H