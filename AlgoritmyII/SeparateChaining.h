#pragma once
#include <iostream>

template<class T>
struct HashNode
{
	HashNode* nextNode;
	T data;
	int key;
	bool isSet;
};

template<class T>
class SeparateChaining
{
private:
	HashNode<T>* hashTable;
	int size;
	void RecursiveDestruct(HashNode<T>*);

public:
	SeparateChaining(int);
	~SeparateChaining();

	void Insert(int, T);
	T Search(int);
	bool Delete(int);
	void PrintStructure();
};

template<class T>
SeparateChaining<T>::SeparateChaining(int size)
{
	this->size = size;
	this->hashTable = new HashNode<T>[this->size];
	for (int i = 0; i < this->size; i++)				//Initialize all first elements of the table
	{
		hashTable[i].data = 0;
		hashTable[i].isSet = false;
		hashTable[i].nextNode = NULL;
	}
}

template<class T>
void SeparateChaining<T>::RecursiveDestruct(HashNode<T>* next)
{
	if (next->nextNode == nullptr)
	{
		delete next;
		return;
	}

	RecursiveDestruct(next->nextNode);
}

template<class T>
SeparateChaining<T>::~SeparateChaining()
{
	for (int i = 0; i < this->size; i++)
		RecursiveDestruct(&hashTable[i]);

	delete[] hashTable;
}

template<class T>
void SeparateChaining<T>::Insert(int key, T value)
{
	HashNode<T>* newNode = new HashNode<T>();		//Create new node object
	newNode->key = key;
	newNode->data = value;
	newNode->nextNode = NULL;
	newNode->isSet = true;
	
	int hash = key % this->size;					//Calculate hash from key

	if (!hashTable[hash].isSet)						//If the first element is not set, place the new node as first element
		hashTable[hash] = *newNode;
	else
	{
		HashNode<T>* next = &hashTable[hash];		//Else we cycle through all elements with same hash, and search for last element (nextNode is nullptr)
		while (next->nextNode)
			next = next->nextNode;
		next->nextNode = newNode;					//Insert the new node at the end of chain
	}
}

template<class T>
T SeparateChaining<T>::Search(int key)
{
	int hash = key % this->size;

	HashNode<T>* next = &hashTable[hash];
	while (next != nullptr && next->key != key)		//Cycle through all elements with same hash, until we reach element, that is nullptr, or we find searched key
		next = next->nextNode;
	return next == nullptr ? 0 : next->data;		//If we found nullptr, return 0, else return found value
}

template<class T>
bool SeparateChaining<T>::Delete(int key)
{
	int hash = key % this->size;

	HashNode<T>* next = &hashTable[hash];
	HashNode<T>* oldNode;
	if (next == nullptr)							//If the first element is nullptr, the searched key is not in the table, we can return false right away
		return false;

	if (hashTable[hash].key == key)					//If the first element is searched key, we take nextNode and place it as the first element of chain and return true
	{
		hashTable[hash] = *hashTable[hash].nextNode;
		return true;
	}

	while (next->nextNode)							//Cycle through chain, until the end (nextNode is nullptr)
	{
		if (next->nextNode->key == key)				//If key value of nextNode is searched key, we take current node, and replace it with current nextNode and return true
		{
			oldNode = next->nextNode;
			next->nextNode = next->nextNode->nextNode;
			delete oldNode;
			return true;
		}
		next = next->nextNode;						//If key value of nextNode is not searched key, we move in the chain one step further
	}

	return false;									//If we reached the end of the cycle (did not find key and reached nextNode is nullptr) we return false
}

template<class T>
void SeparateChaining<T>::PrintStructure()
{
	for (int i = 0; i < this->size; i++)
	{
		HashNode<T>* next = &hashTable[i];
		while (next)
		{
			std::cout << next->key << ": " << next->data << " => ";
			next = next->nextNode;
		}
		std::cout << std::endl;
	}
}