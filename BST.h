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
	BST();
	~BST();

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
	void insertHelper(T& value, Node<T>*& node);
	bool retrieveHelper(const string director, const string movieName, T*& holder, Node<T>* node);
	bool retrieveHelper(const string movieTitle, const int releaseYear, T*& holder, Node<T>* node);
	bool retrieveHelper(const string maFname, const string maLname, const int releaseMonth, const int releaseYear, T*& holder, Node<T>* node);
	bool retrieveSimilarClassicHelper(const string majorActorFirstName, const string majorActorLastName, const string title, const string director, const int releaseMonth, const int releaseYear, T*& holder, Node<T>* node);
	void deleteTreeHelper(Node<T>* node);
	void displayHelper(Node<T>* current, int level) const;
};

template<class T>
BST<T>::BST()
{
	root = nullptr;
}

template<class T>
BST<T>::~BST()
{
	if (root != nullptr)
	{
		deleteTree();
	}
}

template<class T>
void BST<T>::insert(T& value)
{
	return insertHelper(value, root);
}

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

template<class T>
bool BST<T>::retrieve(const string director, const string movieName, T*& holder)
{
	return retrieveHelper(director, movieName, holder, root);
}

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

template<class T>
bool BST<T>::retrieve(const string movieTitle, const int releaseYear, T*& holder)
{
	return retrieveHelper(movieTitle, releaseYear, holder, root);
}

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

template<class T>
bool BST<T>::retrieve(const string maFname, const string maLname, const int releaseMonth, const int releaseYear, T*& holder)
{
	return retrieveHelper(maFname, maLname, releaseMonth, releaseYear, holder, root);
}

template<class T>
inline bool BST<T>::retrieveSimilarClassic(const string majorActorFirstName, const string majorActorLastName, const string title, const string director, const int releaseMonth, const int releaseYear, T*& holder)
{
	return retrieveSimilarClassicHelper(majorActorFirstName, majorActorLastName, title, director, releaseMonth, releaseYear, holder, this->root);
}

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

template<class T>
void BST<T>::display() const
{
	displayHelper(root, 0);
}

template<class T>
void BST<T>::displayHelper(Node<T>* node, int level) const
{
	if (node != nullptr) {

		displayHelper(node->left, level);
		cout << (node->data) << endl;
		displayHelper(node->right, level);
	}
}
#endif

