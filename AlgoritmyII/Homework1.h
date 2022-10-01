#pragma once
class Homework1
{
private:
	int *elements;
	int *elementsBackup;
	int elementsLength;
	int s;

public:
	Homework1(unsigned int, int);
	~Homework1();

	void Example1();

	void GenerateUniqueElements();
	void ResetElements();
};