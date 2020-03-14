#include "HashTable.h"


HashTable::HashTable() {
	table = new Node *[DEFAULT_TABLE_SIZE+1];
	for (int i = 0; i < DEFAULT_TABLE_SIZE+1; i++) {
		table[i] = nullptr;
	}
}

HashTable::~HashTable()
{
	this->clear();
}
bool HashTable::insert(Customer *cust)
{
	if (!this->contains(cust)) {
		int index = hash(cust->getCustomerID());
		Node *curr = new Node( *cust);
		curr->next = table[index];
		table[index] = curr;
		return true;
	}
	return false;
}

bool HashTable::retrieve(int key, Customer *&holder)
{
	
	Node *curr = table[hash(key)];
	while (curr != nullptr) {
		if (curr->data.getCustomerID() == key) {
			holder = &curr->data;
			return true;
		}
		curr = curr->next;
	}
	holder = nullptr;
	return false;
}


bool HashTable::contains(Customer *cust)
{
	int index = hash(cust->getCustomerID());
	Node *curr = table[index];
	while (curr != nullptr) {
		if (curr->data == *cust){
			return true;
		}
		curr = curr->next;
	}
	return false;
}

bool HashTable::contains(int key) {
	int index = hash(key);
	Node *curr = table[index];
	while (curr != nullptr) {
		if (curr->data.getCustomerID() == key) {
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