#include "Sample.h"

void fun()
{
	std::cout << "Hello from fun!\n";
}

int GetIntInput()
{
	int x;

	do
	{
		std::cout << "Please input an integer: ";
		std::cin >> x;
	} while (x == 0);

	return x;
}

std::string GetStringInput()
{
	std::string userInput;
	std::cout << "Please enter a string: ";
	std::getline(std::cin, userInput);

	return userInput;
}

void Mean()
{
	float x, y;
	std::cout << "Please input 2 floats: ";
	std::cin >> x;
	std::cin >> y;

	std::cout << (x + y) / 2 << std::endl;
}
