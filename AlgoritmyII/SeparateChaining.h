#pragma once
struct HashNode
{

	HashNode* nextNode;
	int data;
};

class SeparateChaining
{
private:
	HashNode* hashTable;
	int size;

public:	//TODO: change int to T, dealocation
	SeparateChaining(int);
	~SeparateChaining();

	void Insert(int, int);
	int Search(int);
	bool Delete(int);
};

