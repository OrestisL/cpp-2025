#pragma once

#include <string>
#include <vector>

namespace classes
{
	class Person 
	{
	private:
		int age = -1;
		std::string name = "";
		std::string lastName = "";

	public:
		Person();
		Person(std::string nameIn, std::string lastNameIn, int ageIn);

		~Person();

		inline void GetName(std::string* nameOut) { *nameOut = name; }

		inline void GetName(std::string& nameOut) { nameOut = name; }

		inline const std::string GetLastName() { return lastName; }

		inline const int GetAge() { return age; }
	};

	struct Transform
	{
		std::vector<float> positions;
		std::vector<float> rotations;
		std::vector<float> scales;
		size_t size;

		Transform();
		Transform(size_t sizeIn);
		~Transform();

		float GetPosition(int index);
		float GetRotation(int index);
		float GetScale(int index);

	private:
		void InitArrays();
	};

	class Object
	{
		Transform* transform;
		// ...
	public:
		inline Object(Transform*& other) { transform = other; }


	};

	struct Position
	{
		float x, y, z;

		Position(float xIn, float yIn, float zIn)
		{
			x = xIn;
			y = yIn;
			z = zIn;
		}

		std::string ToString() const
		{
			return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
		}
	};

	class Base
	{
	private:
		static int count;

	public:
		inline static int GetCount() { return count; }
		Base() { count++; }
		~Base() { count--; }
		virtual void F();
	};

	class Derived : public Base
	{
	public:
		void F() override;
	};

	class Derived2 : public Base
	{
	public:
		void F() override;
	};

}
