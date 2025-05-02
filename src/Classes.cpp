#include "Classes.h"
#include <random>
#include <iostream>

namespace classes 
{
#pragma region Person
	Person::Person() 
		: name("John"), lastName("Smith"), age(45)
	{
	}

	Person::Person(std::string nameIn, std::string lastNameIn, int ageIn)
		: name(nameIn), lastName(lastNameIn), age(ageIn)
	{
	}

	Person::~Person()
	{
	}

#pragma endregion // Person
#pragma region Transform
	Transform::Transform() : size(0)
	{
		InitArrays();
	}

	Transform::Transform(size_t sizeIn) : size(sizeIn)
	{
		InitArrays();
	}

	Transform::~Transform() 
	{
	}

	void Transform::InitArrays() 
	{
		positions.resize(size);
		rotations.resize(size);
		scales.resize(size);

		for (size_t i = 0; i < size; i++)
		{
			positions[i] = i * 0.2 / 0.5;
			rotations[i] = i * 0.1 / 14.0;
			scales[i] = i * 0.7 / 0.5;
		}
	}

	float Transform::GetPosition(int index)
	{
		if (index >= size || index < 0)
			return std::numeric_limits<float>::min();

		return positions[index];
	}

	float Transform::GetRotation(int index)
	{
		if (index >= size || index < 0)
			return std::numeric_limits<float>::min();

		return rotations[index];
	}

	float Transform::GetScale(int index)
	{
		if (index >= size || index < 0)
			return std::numeric_limits<float>::min();

		return scales[index];
	}
#pragma endregion

	void Base::F() 
	{
		std::cout << "F from Base\n";
	}

	void Derived::F() 
	{
		int x = 5;
		x += 18203;
		std::cout << std::to_string(x) << "\n";
	}

	void Derived2::F()
	{
		std::cout << "F from derived2\n";
	}

	int Base::count = 0;
}