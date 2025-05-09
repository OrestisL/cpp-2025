#pragma once
#include <vector>
#include "Classes.h"
#include <assert.h>

namespace SectionMath
{
	float SectionArea(const std::vector<classes::Position>& positions)
	{
		// need more than 2 points and odd number of points
		assert(positions.size() > 2 && positions.size() % 2 != 0);

		float result = 0;
		for (size_t i = 0; i < positions.size(); i++)
		{
			float coeff;
			if (i == 0 || i == positions.size() - 1)
				coeff = 1.0f;
			else
			{
				if (i % 2 == 0)
					coeff = 4;
				else
					coeff = 2;
			}

			result += coeff * positions[i].y;
		}

		float h = positions[1].z - positions[0].z;

		result *= 2 * h / 3;

		return result;
	}

	float Volume(const std::vector<float>& areas, float h)
	{
		// need more than 2 points and odd number of points
		assert(areas.size() > 2 && areas.size() % 2 != 0);

		float result = 0;
		for (size_t i = 0; i < areas.size(); i++)
		{
			float coeff;
			if (i == 0 || i == areas.size() - 1)
				coeff = 1.0f;
			else
			{
				if (i % 2 == 0)
					coeff = 4;
				else
					coeff = 2;
			}

			result += coeff * areas[i];
		}

		result *= h / 3;

		return result;
	}
}