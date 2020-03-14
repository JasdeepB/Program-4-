#include "HashTable.h"


HashTable::HashTable() {
	table = new Node *[DEFAULT_TABLE_SIZE];
	for (int i = 0; i < DEFAULT_TABLE_SIZE; i++) {
		table[i] = nullptr;
	}
}

HashTable::~HashTable()
{
	this->clear();
}
bool HashTable::insert(int key, Customer *cust)
{
	int index = hash(key);
	Node *curr = table[index];
	Node *prev = curr;
		if (curr == nullptr) {
			curr = new Node;
			curr->data = cust;
			return true;
		}

	if (curr->data == cust) {
		cout << cust << "already exists";
		return false;
	}

	while (curr != nullptr) {
		if (curr->data == cust) {
			cout << cust << "already exists";
			return false;
		}
		prev = curr;
		curr = curr->next;
	}
	curr = new Node;
	prev->next = curr;
	curr->data = cust;
	return true;
}

Customer *HashTable::retrieve(int key)
{
	if (table[hash(key)] == nullptr) {
		return nullptr;
	}
	Node *curr = table[hash(key)];
	while (curr != nullptr) {
		if (curr->data->getCustomerID() == key) {
			return curr->data;
		}
		curr = curr->next;
	}
	return nullptr;
}


bool HashTable::contains(int key)
{
	if (table[hash(key)] == nullptr) {
		return false;
	}
	Node *curr = table[hash(key)];
	while (curr != nullptr) {
		if (curr->data->getCustomerID() == key) {
			return true;
		}
		curr = curr->next;
	}
	return false;
}
void HashTable::clear(){

	for(int i = 0; i <DEFAULT_TABLE_SIZE; i++){
		Node *curr = table[i];
	
		while(curr != nullptr){
			Node *temp = curr;
			curr = curr->next;
			delete temp->data;
			delete temp;
			temp = nullptr;
		}
	}
	delete[] table;
}

int HashTable::hash(int key)
{
	return key % DEFAULT_TABLE_SIZE;
}