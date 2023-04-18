#include "day_4.h"



using big_vec = std::vector<std::vector<int>>; // Should contain 5 x 5 vector of ints


class Bingo_game
{
private:
	std::vector<int> numbers{};
	std::vector<big_vec> boards{};

public:
	std::vector<int> get_numbers() { return numbers; }
	std::vector<big_vec> get_boards() { return boards; }

	void read_file()
	{
		std::string file_path{ get_file_path("4", false) };

		std::fstream newfile;
		newfile.open(file_path, std::ios::in); // open file for reading

		if (!newfile) std::cerr << "Could not open the file!" << std::endl;

		int counter{ 0 };
		if (newfile.is_open())
		{
			std::string line{};
			
			big_vec board{};
			while (std::getline(newfile, line))
			{
				if (counter == 0)
				{
					numbers = split_string_by_delim_return_int(line, ',');
					counter++;
					continue;
				}
				else if (counter > 1)
				{
					if (line.empty())
					{
						
						// Add board to storage
						boards.push_back(board);
						// Clear the board
						board.clear();
					}
					else
					{
						std::vector<int> num_line = split_string_by_delim_return_int(line, ' ');
						board.push_back(num_line);
					}
				}


				counter++;
			}
			newfile.close();

			// Add last board
			
			boards.push_back(board);

		}

	}
};


void day_4_solver()
{
	// Start with reading the data.
	// First line contains the numbers that will be used for picking bingo numbers

	// Rest of text file is whitespace, 5 x 5 bingo board, ...

	Bingo_game bingo;

	bingo.read_file();
	
	std::vector<big_vec> boards = bingo.get_boards();
	
	for (big_vec board : boards)
	{
		for (std::vector<int> line : board)
		{
			for (int i : line)
			{
				std::cout << i << ' ';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}
	

}