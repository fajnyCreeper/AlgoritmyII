#pragma once
class Components
{
public:
	static void CreateArraySequenceValues(int*&, unsigned int);
	static void CreateArrayRandomValues(int*&, unsigned int);
	static void DuplicateArray(int*, unsigned int, int*&);
	static void PrintElements(int*, unsigned int);
	static int Compare(const void*, const void*);
	static void MeasureMethod(void(*)(void*), void*);
	static void GenerateUniqueElements(int*, unsigned int);
};

