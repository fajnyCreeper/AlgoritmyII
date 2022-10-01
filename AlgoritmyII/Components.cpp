#include "Components.h"
#include <iostream>
#include <chrono>

void Components::CreateArraySequenceValues(int*& elements, unsigned int elementsLength)
{
    for (int i = 0; i < elementsLength; i++)
    {
        elements[i] = i;
    }
}

void Components::CreateArrayRandomValues(int *&elements, unsigned int elementsLength)
{
    srand(time(0));

    for (int i = 0; i < elementsLength; i++)
    {
        elements[i] = 1 + (rand() % 10);
    }
}

void Components::DuplicateArray(int *elements, unsigned int elementsLength, int *&elementsOutput)
{
    for (int i = 0; i < elementsLength; i++)
    {
        elementsOutput[i] = elements[i];
    }
}

void Components::PrintElements(int *elements, unsigned int elementsLength)
{
    std::cout << '{';
    for (int i = 0; i < elementsLength; i++)
    {
        std::cout << elements[i] << ';';
    }
    std::cout << '}' << std::endl;
}

int Components::Compare(const void *a, const void *b)
{
    if (*(int*)a < *(int*)b) return -1;	// Znamenka meni serazeni
    if (*(int*)a == *(int*)b) return 0;
    if (*(int*)a > *(int*)b) return 1;	//
}

void Components::MeasureMethod(void (*function)(void*), void *context)
{
    auto start = std::chrono::high_resolution_clock::now();
    function(context);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " milliseconds" << std::endl;
}

void Components::GenerateUniqueElements(int* elements, unsigned elementsLength)
{
    for (int i = 0; i < elementsLength; i++)
    {
        srand(time(0));

        int num = (rand() % 10) + 1;
        elements[i] = num;
        for (int j = 0; j < i; j++)
        {
            if (num == elements[j])
                i--;
        }
    }
}