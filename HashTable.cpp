// ------------------------------------------------ HashTable.cpp -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the implementation file for the HashTable class. 
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------

#include "HashTable.h"

//constructor
HashTable::HashTable() {
	
	this->size = 0;
	this->capacity = 10;
	this->table = new Node * [10]();
}
//end constructor

//destructor
HashTable::~HashTable()
{
	this->clear();
}
//end destructor 

// -------------------------------- insert() --------------------------------
// Description
// insert: inserts a new customer object into the hash table
// preconditions:valid customer object, valid hashtable object
// postconditions: customer object is inserted into the hashtable 
// -----------------------------------------------------------------------------
bool HashTable::insert(Customer *cust)
{
	if (!(this->contains(cust))) 
	{
		int index = hash(cust->getCustomerID());
		Node *curr = new Node(*cust);
		curr->next = table[index];
		table[index] = curr;
		size++;
		return true;
	}
	return false;
}
//end insert

// -------------------------------- retrieve() --------------------------------
// Description
// retrieve: finds the specified customer object and stores it in a provided pointer
// preconditions: empty pointer, a key value
// postconditions: boolean, pointer with specified customer value or nullptr
// -----------------------------------------------------------------------------
bool HashTable::retrieve(int key, Customer *&holder)
{
	

	int index = hash(key);
	Node* current = table[index];
	while (current != NULL)
	{
		if (current->data.customerID == key)
		{
			holder = &current->data;
			return true;
		}
		current = current->next;
	}
	return false;
}
//end retrieve

// -------------------------------- contains() --------------------------------
// Description
// containse: checks whether the customer object is in the hashtable based on the provided customer object
// preconditions:valid customer object
// postconditions: the customer object has been shown to be in the hashtable
// -----------------------------------------------------------------------------
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
//end contains

// -------------------------------- contains() --------------------------------
// Description
// containse: checks whether the customer object is in the hashtable based on a provided key
// preconditions:key
// postconditions: the customer object has been shown to be in the hashtable
// -----------------------------------------------------------------------------
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
// end contains

// -------------------------------- clear() --------------------------------
// Description
// clear:deletes the contents of the hashtable 
// preconditions: a valid hashtable object
// postconditions: hashtable is deleted
// -----------------------------------------------------------------------------
void HashTable::clear(){

	for(int i = 0; i < capacity; i++){
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
//end clear

// -------------------------------- hash() --------------------------------
// Description
// hash: creates a hash coded based on the provided int 
// preconditions:none
// postconditions: none
// -----------------------------------------------------------------------------
int HashTable::hash(int key)
{
	return key % capacity;
}
//end hash