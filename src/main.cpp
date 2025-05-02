#include <iostream>
#include <vector>
#include "Classes.h"
#include "Files.h"
#include <cmath>

void ShowArray(float* array, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << i << " : " << (array + i) << "\n";
	}
}

std::string PrintArray(std::vector<float> v)
{
	std::string result;
	for (size_t i = 0; i < v.size(); i++)
	{
		result += std::to_string(i) + ", " + std::to_string(v[i]) + "\n";
	}
	return result;
}

void ShowVector(std::vector<float> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << i << " , " << v[i] << "\n";
	}
}

std::vector<classes::Position> PositionInsideCircle(classes::Position center, float radius, size_t numberPoints = 120) 
{
	float theta;
	std::vector<classes::Position> positions;

	for (size_t i = 0; i < numberPoints; i++)
	{
		theta = (float)i * 3.14159 / 180; // radians
		float x = center.x + cos(theta);
		float y = center.y + sin(theta);
		float z = 5;

		positions.push_back(classes::Position(x, y, z));
	}

	return positions;
}

void PrintPositionArray(std::vector<classes::Position> positions)
{
	std::string result;
	for (size_t i = 0; i < positions.size(); i++)
	{
		classes::Position pos = positions[i];
		result += std::to_string(pos.x) + ", " + std::to_string(pos.y) + ", " + std::to_string(pos.z) + "\n";
	}

	std::cout << result;
}

int size{ };
float* array;
std::vector<float> floatvector;
std::vector<classes::Position> posVec;

void Arrays()
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

int main()
{
	// create posVec and write it to a file
	//posVec = PositionInsideCircle(classes::Position(0, 0, 0), 4);
	//
	//std::string positionsString;
	//for (size_t i = 0; i < posVec.size(); i++)
	//{
	//	positionsString += posVec[i].ToString() + "\n";
	//}
	//
	//Files::WriteFile("Positions.txt", positionsString);

	// read posVec from file
	//Files::ReadPositionArrayFromFile("Positions.txt", posVec);
	//PrintPositionArray(posVec);

	// polymorphism
	// pointers to classes::Base because
	// the derived classes may not have the same size as Base
	// but pointers to Base will have the same size as pointers
	// to derived classes
	std::vector<classes::Base*> v;
	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			v.push_back(new classes::Derived());
		}
		else
		{
			v.push_back(new classes::Derived2());
		}
	}

	for (size_t i = 0; i < 10; i++)
	{
		v[i]->F();
	}

	std::cout << classes::Base::GetCount();
}

