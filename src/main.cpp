#include <iostream>
#include <vector>
#include "Classes.h"
#include "Files.h"
#include <cmath>
#include "SectionMath.h"

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

std::vector<classes::Position> Sections(float radius, int sectionId, size_t numberPoints = 15)
{
	float theta;
	std::vector<classes::Position> positions;

	for (size_t i = 0; i <= numberPoints; i++)
	{
		theta = (float)i * 0.25 * 3.14159 / 180; // radians for quarter cirlce
		float x = sectionId;
		float z = i * radius / numberPoints;
		float y = z * (1 - cos(theta)) * 500;

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

std::string GetSectionsString(const std::vector<classes::Position>& section, int index)
{
	std::string header = "#Section " + std::to_string(index) + "\n";

	std::string sectionString;

	for (size_t i = 0; i < section.size(); i++)
	{
		sectionString += section[i].ToString() + "\n";
	}

	return header + sectionString;
}


int main()
{
	int sections = 25;
	std::string sectionString;
	size_t pointsPerSection = 15;

	for (size_t i = 0; i < sections; i++)
	{
		int index = i + 1;
		posVec = Sections(15, index, pointsPerSection);

		sectionString += GetSectionsString(posVec, index);
	}
	//create posVec and write it to a file

	Files::WriteFile("Sections.txt", sectionString);

	// read posVec from file
	//Files::ReadPositionArrayFromFile("Positions.txt", posVec);
	//PrintPositionArray(posVec);

	// polymorphism
	// pointers to classes::Base because
	// the derived classes may not have the same size as Base
	// but pointers to Base will have the same size as pointers
	// to derived classes
	//std::vector<classes::Base*> v;
	//for (size_t i = 0; i < 10; i++)
	//{
	//	if (i % 2 == 0)
	//	{
	//		v.push_back(new classes::Derived());
	//	}
	//	else
	//	{
	//		v.push_back(new classes::Derived2());
	//	}
	//}
	//
	//for (size_t i = 0; i < 10; i++)
	//{
	//	v[i]->F();
	//}
	//
	//
	//std::cout << classes::Base::GetCount();

	// get specific section from file
	int sectionId = 4;

	std::vector<classes::Position> section;
	Files::ReadAllSectionsFromFile("Sections.txt", section);
	std::vector<float> areas;
	for (size_t i = 0; i < section.size(); i += pointsPerSection + 1)
	{
		std::vector<classes::Position>::const_iterator firstElement = section.begin() + i;
		std::vector<classes::Position>::const_iterator lastElement = firstElement + pointsPerSection;
		std::vector<classes::Position> currentSection(firstElement, lastElement);

		areas.push_back(SectionMath::SectionArea(currentSection));
	}

	std::cout << SectionMath::Volume(areas, 1) << " m3\n";
	//
	//for (size_t i = 0; i < section.size(); i++)
	//{
	//	sectionString += section[i].ToString() + "\n";
	//}
	//
	//std::cout << sectionString;
}

