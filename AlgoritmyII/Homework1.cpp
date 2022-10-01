#include "Homework1.h"
#include <iostream>
#include "Components.h"

Homework1::Homework1(unsigned int elementsLength, int s)
{
	this->elementsLength = elementsLength;
	this->s = s;

	this->elements = new int[this->elementsLength];
	this->elementsBackup = new int[this->elementsLength];

	Components::GenerateUniqueElements(this->elements, this->elementsLength);
	Components::DuplicateArray(this->elements, this->elementsLength, this->elementsBackup);
}

Homework1::~Homework1()
{
	delete[] this->elements;
	delete[] this->elementsBackup;
}

void Homework1::Example1()
{
	Components::PrintElements(this->elements, this->elementsLength);
	std::qsort(this->elements, this->elementsLength, sizeof(int), Components::Compare);

	int left = 0;
	int right = this->elementsLength - 1;
	int sum;
	while (left < right)
	{
		sum = this->elements[left] + this->elements[right];
		if (sum == this->s)
		{
			std::cout << "Pair found: " << this->elements[left] << ", " << this->elements[right] << std::endl;
			return;
		}
		else if (sum < this->s)
			left++;
		else
			right--;
	}
	std::cout << "Pair not found" << std::endl;
}

void Homework1::GenerateUniqueElements()
{
	Components::GenerateUniqueElements(this->elements, this->elementsLength);
}


void Homework1::ResetElements()
{
	for (int i = 0; i < this->elementsLength; i++)
	{
		this->elements[i] = this->elementsBackup[i];
	}
}