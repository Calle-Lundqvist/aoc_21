#include "day_1.h"




// the number of times a depth measurement increases

int day_1_solver_a(std::string day, bool real)
{
	int ans{};


	std::vector<int> input_ints{ read_line_ints_from_file(day, real) };


	for (int i = 1; i < input_ints.size(); i++)
	{
		if (input_ints[i] > input_ints[i - 1])
		{
			ans++;
		}
	}



	return ans;
}

// the number of times the sum of measurements in this sliding window increases

int day_1_solver_b(std::string day, bool real)
{
	int ans{};


	std::vector<int> input_ints{ read_line_ints_from_file(day, real) };

	for (int i = 2; i < input_ints.size() - 1; i++)
	{
		if (input_ints[i - 1] + input_ints[i] + input_ints[i + 1] > input_ints[i - 2] + input_ints[i - 1] + input_ints[i])
		{
			ans++;
		}
	}


	return ans;
}

