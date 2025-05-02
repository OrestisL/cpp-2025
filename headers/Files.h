#ifndef FILES_H
#define FILES_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

namespace Files
{
	bool ReadFile(const std::string& path, std::string& contents)
	{
		std::ifstream stream(path, std::ios::in);
		if (!stream.is_open())
		{
			return false;
		}
		std::string line;
		while (std::getline(stream, line))
		{
			contents += line;
		}

		return true;
	}

	bool ReadFloatArrayFromFile(const std::string& path, std::vector<float>& values)
	{
		std::ifstream stream(path, std::ios::in);
		if (!stream.is_open())
		{
			return false;
		}

		std::string line;
		while (std::getline(stream, line))
		{
			if (line.size() == 0)
				break;
			std::istringstream stringStream(line);
			std::string index, value;

			// read from string stream into index and value
			stringStream >> index >> value;

			int idx = stoi(index);
			float val = stof(value);

			values.push_back(val);
		}

		return true;
	}

	bool ReadPositionArrayFromFile(const std::string& path, std::vector<classes::Position>& values)
	{
		std::ifstream stream(path, std::ios::in);
		if (!stream.is_open())
		{
			return false;
		}

		std::string line;
		while (std::getline(stream, line))
		{
			if (line.size() == 0)
				break;

			std::istringstream stringStream(line);
			std::string x, y, z;

			// read from string stream into index and value
			stringStream >> x >> y >> z;

			float posx = stof(x);
			float posy = stof(y);
			float posz = stof(z);

			values.push_back(classes::Position(posx, posy, posz));
		}

		return true;
	}

	bool WriteFile(const std::string& path, const std::string& contents)
	{
		std::ofstream stream(path, std::ios::out);
		if (!stream.is_open())
		{
			return false;
		}

		stream.write(contents.c_str(), contents.size());
		return true;
	}
}

#endif // !FILES_H
