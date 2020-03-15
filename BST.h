// ------------------------------------------------ BST.h -------------------------------------------------------
// Jasdeep Brar, Cameron Ufland CSS343 C
// Creation Date: March 1, 2020
// Date of Last Modification: March 14, 2020
// --------------------------------------------------------------------------------------------------------------------
// This is the header and implementation for our Binary Search Tree.
// --------------------------------------------------------------------------------------------------------------------
//The requirements for this assignment were specified by Wooyoung Kim via class
// and canvas.
// --------------------------------------------------------------------------------------------------------------------
#ifndef  BST_HEADER
#define BST_HEADER
#include<iostream>
#include <string>
#include "Movie.h"

using namespace std;

template<class T>


struct Node
{
	Node(T d = nullptr, Node* r = nullptr, Node* l = nullptr)
	{
		data = d;
		left = l;
		right = r;	
	}

	T data;
	Node<T>* left = nullptr;
	Node<T>* right = nullptr;
};

template<class T>
class BST
{
public:
	//constructors and destructors
	BST();
	~BST();
	//insert and retrieve functions
	void insert(T& data);
	bool retrieve(const string movieTitle, const int releaseYear, T*& holder); //Comedy Movies
	bool retrieve(const string director, const string movieName, T*& holder); //Drama Movies
	bool retrieve(const string majorActorFirstName, const string majorActorLastName, const int releaseMonth, const int releaseYear, T*& holder); //Classic Movies
	bool retrieveSimilarClassic(const string majorActorFirstName, const string majorActorLastName, const string title, const string director, const int releaseMonth, const int releaseYear, T*& holder);
	bool isEmpty() const;
	void deleteTree();
	void display() const;

private:
	Node<T>* root;
	//helper methods
	void insertHelper(T& value, Node<T>*& node);
	bool retrieveHelper(const string director, const string movieName, T*& holder, Node<T>* node);//drama
	bool retrieveHelper(const string movieTitle, const int releaseYear, T*& holder, Node<T>* node);//comedy
	bool retrieveHelper(const string maFname, const string maLname, const int releaseMonth, const int releaseYear, T*& holder, Node<T>* node);//classic
	bool retrieveSimilarClassicHelper(const string majorActorFirstName, const string majorActorLastName, const string title, const string director, const int releaseMonth, const int releaseYear, T*& holder, Node<T>* node);
	void deleteTreeHelper(Node<T>* node);
	void displayHelper(Node<T>* current, int level) const;
};
//end class "header" file

//constructor
template<class T>
BST<T>::BST()
{
	root = nullptr;
}
//end constructor

//destructor
template<class T>
BST<T>::~BST()
{
	if (root != nullptr)
	{
		deleteTree();
	}
}
//end destructor

// -------------------------------- insert() --------------------------------
// Description
// insert:inserts a value into the BST
// preconditions:valid object of class T
// postconditions: the object is in the BST
// -----------------------------------------------------------------------------
template<class T>
void BST<T>::insert(T& value)
{
	return insertHelper(value, root);
}
//end insert

// -------------------------------- insertHelper() --------------------------------
// Description
// insertHelper:recursive helper method to a value into the BST
// preconditions:valid object of class T
// postconditions: the object is in the BST
// -----------------------------------------------------------------------------
template<class T>
void BST<T>::insertHelper(T& value, Node<T>*& node)
{
	if (node == nullptr)
	{
		node = new Node<T>(value);
	}
	else if (node->data == value)
	{
		node->data.addToStock(value.getStock());
	}
	else if (node->data > value)
	{
		insertHelper(value, node->left);
	}
	else if (node->data < value)
	{
		insertHelper(value, node->right);
	}
}
//insertHelper



// -------------------------------- retrieve() --------------------------------
// Description
// retrieve (Drama): retrieves a specified object from the BST. It uses the sorting attributes
//for each movie
// preconditions:empty pointer to hold object
// postconditions: pointer will hold object or will be nullptr
// -----------------------------------------------------------------------------
template<class T>
bool BST<T>::retrieve(const string director, const string movieName, T*& holder)
{
	return retrieveHelper(director, movieName, holder, root);
}
//end retrieve(Drama)

// -------------------------------- retrieveHelper() --------------------------------
// Description
// retrieveHelper(Drama): helper function for recursive search of BST
// preconditions:valid object of class T
// postconditions: the object is in the BST
// -----------------------------------------------------------------------------
template<class T>
bool BST<T>::retrieveHelper(const string director, const string movieName, T*& holder, Node<T>* node)
{
	if (node == nullptr)
	{
		return false;
	}
	else if ((node->data.getDirector() == director) && (node->data.getTitle() == movieName))
	{
		//Thank goodness I found this https://www.geeksforgeeks.org/reinterpret_cast-in-c-type-casting-operators/
		holder = reinterpret_cast<T*>(node);
		return true;
	}
	else
	{
		return retrieveHelper(director, movieName, holder, node->left) || retrieveHelper(director, movieName, holder, node->right);
	}
	return false;
}
//end retrieveHelper(Drama)

// -------------------------------- retrieve() --------------------------------
// Description
// retrieve (Comedy): retrieves a specified object from the BST. It uses the sorting attributes
//for each movie
// preconditions:empty pointer to hold object
// postconditions: pointer will hold object or will be nullptr
// -----------------------------------------------------------------------------
template<class T>
bool BST<T>::retrieve(const string movieTitle, const int releaseYear, T*& holder)
{
	return retrieveHelper(movieTitle, releaseYear, holder, root);
}
//end retrieve(Comedy)

// -------------------------------- retrieveHelper() --------------------------------
// Description
// retrieveHelper(Comedy): helper function for recursive search of BST
// preconditions:valid object of class T
// postconditions: the object is in the BST
// -----------------------------------------------------------------------------
template<class T>
bool BST<T>::retrieveHelper(const string movieTitle, const int releaseYear, T*& holder, Node<T>* node)
{
	if (node == nullptr)
	{
		return false;
	}
	else if ((node->data.getTitle() == movieTitle) && (node->data.getReleaseYear() == releaseYear))
	{
		holder = reinterpret_cast<T*>(node);
		return true;
	}
	else
	{
		return retrieveHelper(movieTitle, releaseYear, holder, node->left) || retrieveHelper(movieTitle, releaseYear, holder, node->right);
	}
	return false;
}
//end retrieveHelper(Comedy)

//// -------------------------------- retrieve() --------------------------------
// Description
// retrieve (Classic): retrieves a specified object from the BST. It uses the sorting attributes
//for each movie
// preconditions:empty pointer to hold object
// postconditions: pointer will hold object or will be nullptr
// -----------------------------------------------------------------------------
template<class T>
bool BST<T>::retrieve(const string maFname, const string maLname, const int releaseMonth, const int releaseYear, T*& holder)
{
	return retrieveHelper(maFname, maLname, releaseMonth, releaseYear, holder, root);
}
//end retrieve(Classic)


//// -------------------------------- retrieveSimilarClassic() --------------------------------
// Description
// retrieveSimilarClassic: finds another classic object with same details but different Main Actor
//for each movie
// preconditions:empty pointer to hold object
// postconditions: pointer will hold object or will be nullptr
// -----------------------------------------------------------------------------
template<class T>
inline bool BST<T>::retrieveSimilarClassic(const string majorActorFirstName, const string majorActorLastName, const string title, const string director, const int releaseMonth, const int releaseYear, T*& holder)
{
	return retrieveSimilarClassicHelper(majorActorFirstName, majorActorLastName, title, director, releaseMonth, releaseYear, holder, this->root);
}
//end retrieveSimilarClassic()

// -------------------------------- retrieveHelper() --------------------------------
// Description
// retrieveHelper(Classic): helper function for recursive search of BST
// preconditions:valid object of class T
// postconditions: the object is in the BST
// -----------------------------------------------------------------------------
template<class T>
bool BST<T>::retrieveHelper(const string maFname, const string maLname, const int releaseMonth, const int releaseYear, T*& holder, Node<T>* node)
{
	if (node == nullptr)
	{
		return false;
	}
	else if ((node->data.getMajorActorFirstName() == maFname) && (node->data.getMajorActorLastName() == maLname) && (node->data.getReleaseYear() == releaseYear) && node->data.getReleaseMonth() == releaseMonth)
	{
		holder = reinterpret_cast<T*>(node);
		return true;
	}
	else
	{
		return retrieveHelper(maFname, maLname, releaseMonth, releaseYear, holder, node->left) || retrieveHelper(maFname, maLname, releaseMonth, releaseYear, holder, node->right);
	}
	return false;
}
//end retrieveHelper(Classic)

// -------------------------------- retrieveSimliarClassicHelper() --------------------------------
// Description
// retrieveSimliarClassicHelper: helper function for recursive search of BST
// preconditions:valid object of class T
// postconditions: the object is in the BST
// -----------------------------------------------------------------------------
template<class T>
inline bool BST<T>::retrieveSimilarClassicHelper(const string majorActorFirstName, const string majorActorLastName, const string title, const string director, const int releaseMonth, const int releaseYear, T*& holder, Node<T>* node)
{
	if (node == nullptr)
	{
		return false;
	}
	else if (node->data.getTitle() == title 
		&& node->data.getDirector() == director 
		&& node->data.getReleaseYear() == releaseYear 
		&& node->data.getReleaseMonth() == releaseMonth
		&& node->data.getStock() > 0 
		&& node->data.getMajorActorFirstName() == majorActorFirstName
		&& node->data.getMajorActorLastName() == majorActorLastName)
	{
		holder = reinterpret_cast<T*>(node);
		return true;
	}
	else
	{
		return retrieveSimilarClassicHelper(majorActorFirstName, majorActorLastName, title, director, releaseMonth, releaseYear, holder, node->left
			|| retrieveSimilarClassicHelper(majorActorFirstName, majorActorLastName, title, director, releaseMonth, releaseYear, holder, node->right));
	}
	return false;
}
//end retrieveSimilarClassicHelper

// -------------------------------- isEmpty() --------------------------------
// Description
// isEmpty: checks to see if the BST is empty
// preconditions:valid BST
// postconditions: the emptiness of the BST is assessed
// -----------------------------------------------------------------------------
template<class T>
bool BST<T>::isEmpty() const
{
	if (root != nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}
//end isEmpty

// -------------------------------- deleteTree() --------------------------------
// Description
// deleteTree: deletes the BST and erases all of its contents
// preconditions:valid BST
// postconditions:empty BST
// -----------------------------------------------------------------------------
template<class T>
void BST<T>::deleteTree()
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		deleteTreeHelper(root);
	}
}
//end deleteTree

// -------------------------------- deleteTreeHelper() --------------------------------
// Description
// deleteTreeHelper: recursive helper function that deletes the BST
// preconditions:valid BST
// postconditions: the empty BST
// -----------------------------------------------------------------------------
template<class T>
void BST<T>::deleteTreeHelper(Node<T>* node)
{
	if (node == nullptr)
	{
		return;
	}

	deleteTreeHelper(node->left);
	deleteTreeHelper(node->right);
	delete node;
	node = nullptr;
}
//end deleteTreeHelper

// -------------------------------- display() --------------------------------
// Description
// display: displays the contents of the BST in cout
// preconditions:valid BST
// postconditions: contents output to cout
// -----------------------------------------------------------------------------
template<class T>
void BST<T>::display() const
{
	displayHelper(root, 0);
}
//end display

//--------------------------------displayHelper()--------------------------------
// Description
// displayHelper:recursive functions that helps to display contents of tree
// preconditions:valid BST
// postconditions: contents output to cout
// -----------------------------------------------------------------------------
template<class T>
void BST<T>::displayHelper(Node<T>* node, int level) const
{
	if (node != nullptr) {

		displayHelper(node->left, level);
		cout << (node->data) << endl;
		displayHelper(node->right, level);
	}
}
//end DisplayHelper

#endif

