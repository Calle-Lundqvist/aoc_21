#include "day_3.h"

void day_3_a()
{
	// Need to find most common bit in corresponding position of all numbers in the diagnostic report

	// Start with reading in file things
	std::vector<std::vector<int>> vec2d{ read_2dVec_ints_from_file("3", true) };


	size_t y_size{ vec2d.size() };
	size_t x_size{ vec2d[0].size() };

	std::string gamma_rate{};
	std::string epsilon_rate{};

	for (int i = 0; i < x_size; i++)
	{
		// Iterate through x_size, i.e. first value for EACH row
		int num_zero{ 0 };
		int num_ones{ 0 };

		for (int j = 0; j < y_size; j++)
		{
			// Iterate through y, i.e. first row.. second row.. and so on
			if (vec2d[j][i] == 0) { num_zero++; }
			if (vec2d[j][i] == 1) { num_ones++; }
		}

		if (num_zero > num_ones)
		{
			gamma_rate += '0';
			epsilon_rate += '1';
		}
		else
		{
			gamma_rate += '1';
			epsilon_rate += '0';
		}
	}

	std::cout << gamma_rate << '\n';
	std::cout << binaryToDecimal(gamma_rate) << '\n';

	std::cout << epsilon_rate << '\n';
	std::cout << binaryToDecimal(epsilon_rate) << '\n';

	std::cout << "Answer is = " << binaryToDecimal(gamma_rate) * binaryToDecimal(epsilon_rate) << '\n';
}



int find_most_common(std::vector<std::vector<int>> &vec2d, int col)
{
	size_t y_size{ vec2d.size() };

	
	
	int num_zero{ 0 };
	int num_ones{ 0 };

	for (int j = 0; j < y_size; j++)
	{
		// Iterate through y, i.e. first row.. second row.. and so on
		if (vec2d[j][col] == 0) { num_zero++; }
		if (vec2d[j][col] == 1) { num_ones++; }
	}

	if (num_zero > num_ones)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	
}

int find_least_common(std::vector<std::vector<int>>& vec2d, int col)
{
	size_t y_size{ vec2d.size() };



	int num_zero{ 0 };
	int num_ones{ 0 };

	for (int j = 0; j < y_size; j++)
	{
		// Iterate through y, i.e. first row.. second row.. and so on
		if (vec2d[j][col] == 0) { num_zero++; }
		if (vec2d[j][col] == 1) { num_ones++; }
	}

	if (num_zero > num_ones)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}


std::vector<std::vector<int>> remove_vec_rows(std::vector<std::vector<int>> &vec2d, int num, int col)
{
	size_t y_size{ vec2d.size() };
	std::vector<std::vector<int>> return_vec{};

	for (int j = 0; j < y_size; j++)
	{
		// Iterate through y, i.e. first row.. second row.. and so on
		if (vec2d[j][col] == num) // Keep this row! i.e. add it to return_vec
		{
			return_vec.push_back(vec2d[j]);
		}

	}

	return return_vec;

}


std::string find_rating(std::vector<std::vector<int>> vec2d, bool oxy)
{

	std::string return_string{};


	for (int i = 0; i < vec2d[0].size(); i++)
	{
		int res{};

		if (oxy) { res = find_most_common(vec2d, i); } // res contains most common bit value
		else{ res = find_least_common(vec2d, i); }

		vec2d = remove_vec_rows(vec2d, res, i); // keeps the correct rows

		if (vec2d.size() == 1)
		{
			for (int r : vec2d[0])
			{
				return_string += r + '0'; // convert to char
			}
			break; // Make sure to stop searching here.
		}
	}
	return return_string;

}


std::string day_3_b(bool oxy)
{
	// Need to find most common bit in corresponding position of all numbers in the diagnostic report

	// Start with reading in file 
	std::vector<std::vector<int>> vec2d{ read_2dVec_ints_from_file("3", true) };

	return find_rating(vec2d, oxy);
}


void day_3_solver()
{
	//day_3_a();

	std::string oxy = day_3_b(true);
	std::string co2 = day_3_b(false);
	std::cout << "Answer is = " << binaryToDecimal(oxy) * binaryToDecimal(co2) << '\n';

	 
}