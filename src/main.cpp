﻿#include <iostream>
#include <vector>

void ShowArray(float* array, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << i << " : " << (array + i) << "\n";
	}
}

void ShowVector(std::vector<float> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << i << " : " << v[i] << "\n";
	}
}

int size{ };
float* array;
std::vector<float> floatvector;

int main()
{
	while (size <= 0) 
	{
		std::cout << "Please enter an integer for the array size: ";
		std::cin >> size;
	}

	array = (float*)_malloca(size * sizeof(float));
	floatvector.resize(size);

	for (size_t i = 0; i < size; i++)
	{
		float temp = (float)i / 10;
		array[i] = temp;
		floatvector[i] = temp;
	}

	floatvector.push_back(100.3);

	ShowArray(array, size);
	ShowVector(floatvector);
}