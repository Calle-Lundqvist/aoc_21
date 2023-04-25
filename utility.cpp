#include "utility.h"


std::string get_file_path(std::string day, bool real)
{
	std::string file_path{};

	if (real)
	{
		file_path = "input_data\\day_" + day + ".txt";
	}
	else
	{
		file_path = "test_data\\day_" + day + ".txt";
	}
	return file_path;
}


std::vector<int> read_line_ints_from_file(std::string day, bool real)
{
	// If file is a text file with integers on each row, use this one
	// returns these integers in a vector
	// Input is a string with current day and a bool if we want to test with real data or with test data.
	std::string file_path{ get_file_path(day, real) };



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

std::vector<std::string> read_all_strings_from_file(std::string day, bool real)
{
	// Simply returns an array where each line is a line from the text document
	std::string file_path{ get_file_path(day, real) };



	std::vector<std::string> vec2d{};


	std::fstream newfile;
	newfile.open(file_path, std::ios::in); // open file for reading

	if (!newfile) std::cerr << "Could not open the file!" << std::endl;

	if (newfile.is_open())
	{
		std::string line{};
		while (std::getline(newfile, line))
		{
			vec2d.push_back(line);

		}
		newfile.close();
	}


	return vec2d;
}

std::vector<std::vector<int>> read_2dVec_ints_from_file(std::string day, bool real)
{
	// If file is a text file with integers on each row, where we want to access vec[i][j], use this one
	// returns these integers in a 2d vector
	// Input is a string with current day and a bool if we want to test with real data or with test data.
	std::string file_path{ get_file_path(day, real) };



	std::vector<std::vector<int>> vec2d{};



	std::fstream newfile;
	newfile.open(file_path, std::ios::in); // open file for reading

	if (!newfile) std::cerr << "Could not open the file!" << std::endl;

	if (newfile.is_open())
	{
		std::string line{};
		while (std::getline(newfile, line))
		{
			std::vector<int> vec{};

			for (char c : line)
			{
				vec.push_back(c - '0'); // -'0' converts to int and removes 48
			}
			vec2d.push_back(vec);
			
		}
		newfile.close();
	}


	return vec2d;
}


std::vector<std::string> split_string_by_delim(std::string str, char delim)
{
	// Splits a string into words, separated by char delim

	std::istringstream iss(str);
	std::vector<std::string> words;

	while (std::getline(iss, str, delim)) 
	{
		words.push_back(str);
	}

	return words;
}

std::vector<std::string> split_string_by_delim(std::string str, std::string delim)
{
	size_t pos_start = 0, pos_end, delim_len = delim.length();

	std::string token;
	std::vector<std::string> words;
	while ((pos_end = str.find(delim, pos_start)) != std::string::npos)
	{
		token = str.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		words.push_back(token);
	}

	words.push_back(str.substr(pos_start));


	return words;
}


std::vector<int> split_string_by_delim_return_int(std::string str, char delim)
{

	// Splits a string into ints, separated by char delim



	std::istringstream iss(str);
	std::vector<int> ints{};

	while (std::getline(iss, str, delim))
	{
		ints.push_back(std::stoi(str));
	}

	return ints;
}

std::vector<int> split_string_by_space_return_int(std::string str)
{
	// Splits a string into ints, separated by char delim

	std::stringstream iss(str);
	int num;
	std::vector<int> ints{};

	while (iss >> num)
	{
		ints.push_back(num);
	}


	return ints;
}






int64_t binaryToDecimal(std::string s)
{
	// Function to convert binary (as string) to decimal (as int)
	/*
		Example: binary 101:
			base is 1, last bit is 1,	add 1*1=1 to result
			base is 2, middle bit is 0, add 0*2=0 to result
			base is 4, first bit is 1,	add 1*4=4 to result
										result is 1+4=5
	*/
	int64_t dec_value = 0;

	// Initializing base value to 1, i.e 2^0
	int base = 1;

	int len = s.length();
	for (int i = len - 1; i >= 0; i--) // Iterate from last bit to first bit
	{
		if (s[i] == '1')			
			dec_value += base;			// If bit is 1, add base of current bit
		base = base * 2;				// Multiply base by 2 to get next base
	}

	return dec_value;
}


bool check_if_diagonal(int x1, int y1, int x2, int y2)
{
	// Checks if two points are diagonal
	return (abs(x1 - x2) == (abs(y1 - y2)));
}