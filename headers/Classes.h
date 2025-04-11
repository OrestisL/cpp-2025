#ifndef CLASSES_H
#define CLASSES_H
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
}

#endif // !CLASSES_H
