#include <iostream>
#include "SeparateChaining.h"

#define N 5
#define M 15

using namespace std;

template <class T>
void deleteElement(SeparateChaining<T>* chain)
{
	int random;
	for (int i = 0; i < N; i++)
	{
		random = rand() % M * 2;
		chain->Delete(random) ? cout << "Prvek s klicem " << random << " vymazan." << endl : cout << "Prvek s klicem " << random << " neni v tabulce" << endl;
	}
}

template <class T>
void searchElement(SeparateChaining<T>* chain)
{
	int random;
	for (int i = 0; i < N; i++)
	{
		random = rand() % M;
		cout << "Hodnota prvku s klicem " << random << ": " << chain->Search(random) << endl;
	}
}

int main(void)
{
	srand(time(0));
	SeparateChaining<int> chainInt = SeparateChaining<int>(N);
	SeparateChaining<char> chainChar = SeparateChaining<char>(N);
	SeparateChaining<float> chainFloat = SeparateChaining<float>(N);

	for (int i = 0; i < M; i++)
	{
		chainInt.Insert(i, rand() % 100);
		chainChar.Insert(i, rand() % 26 + 'a');
		chainFloat.Insert(i, (float)(rand() % 100) / 100.0);
	}

	int random;
	cout << "---INT---" << endl;
	chainInt.PrintStructure();
	cout << "---" << endl;
	deleteElement<int>(&chainInt);
	cout << "---" << endl;
	searchElement<int>(&chainInt);
	cout << "---" << endl;
	chainInt.PrintStructure();

	cout << endl << "---CHAR---" << endl;
	chainChar.PrintStructure();
	cout << "---" << endl;
	deleteElement<char>(&chainChar);
	cout << "---" << endl;
	searchElement<char>(&chainChar);
	cout << "---" << endl;
	chainChar.PrintStructure();

	cout << endl << "---FLOAT---" << endl;
	chainFloat.PrintStructure();
	cout << "---" << endl;
	deleteElement<float>(&chainFloat);
	cout << "---" << endl;
	searchElement<float>(&chainFloat);
	cout << "---" << endl;
	chainFloat.PrintStructure();
	


	return 0;
}