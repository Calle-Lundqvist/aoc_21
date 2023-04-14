#include "utility.h"

std::vector<int> read_line_ints_from_file(std::string day, bool real)
{
	// If file is a text file with integers on each row, use this one
	// returns these integers in a vector
	// Input is a string with current day and a bool if we want to test with real data or with test data.
	std::string file_path{};

	if (real)
	{
		file_path = "input_data\\day_" + day + "_data.txt";
	}
	else
	{
		file_path = "test_data\\day_" + day + "_test.txt";
	}


	std::vector<int> vec{};


	std::fstream newfile;
	newfile.open(file_path, std::ios::in); // open file for reading

	if (!newfile) std::cerr << "Could not open the file!" << std::endl;

	if (newfile.is_open())
	{
		std::string line{};
		while (std::getline(newfile, line))
		{
			vec.push_back(std::stoi(line));
		}
		newfile.close();
	}


	return vec;
}