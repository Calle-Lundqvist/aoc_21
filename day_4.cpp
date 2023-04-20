#include "day_4.h"



using vec2d = std::vector<std::vector<int>>; // Should contain 5 x 5 vector of ints


class Bingo_game
{
private:
	std::vector<int> numbers{};
	std::vector<vec2d> boards{};
	std::vector<vec2d> bingo_results{};
	std::vector<int> boards_done{};

public:
	std::vector<int> get_numbers() { return numbers; }
	std::vector<vec2d> get_boards() { return boards; }
	std::vector<vec2d>& get_results() { return bingo_results; }
	std::vector<int>& get_boards_done() { return boards_done; }

	void read_file()
	{
		std::string file_path{ get_file_path("4", true) };

		std::fstream newfile;
		newfile.open(file_path, std::ios::in); // open file for reading

		if (!newfile) std::cerr << "Could not open the file!" << std::endl;

		int counter{ 0 };
		if (newfile.is_open())
		{
			std::string line{};
			
			vec2d board{};
			vec2d bingo_result{};

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
						boards_done.push_back(0);
						bingo_results.push_back(bingo_result);
						// Clear the board
						board.clear();
						bingo_result.clear();
					}
					else
					{
						std::vector<int> num_line = split_string_by_space_return_int(line);
						board.push_back(num_line);
						std::vector<int> zero_vec(num_line.size());
						bingo_result.push_back(zero_vec);
					}
				}


				counter++;
			}
			newfile.close();

			// Add last board
			
			boards.push_back(board);
			bingo_results.push_back(bingo_result);
			boards_done.push_back(0);

		}

	}
};


bool check_if_win(const vec2d& bingo_result)
{
	// All numbers in a row or in a column are 1

	// Check rows
	for (std::vector<int> row : bingo_result) // walk through lines
	{
		if ((row[0] == 1) && (std::equal(row.begin() + 1, row.end(), row.begin())))
		{
			return true;
		}
	}

	// Check cols
	for (int i = 0; i < bingo_result.size(); i++) // walk through lines
	{
		if ((bingo_result[0][i] == 1) && (bingo_result[1][i] == 1) &&
			(bingo_result[2][i] == 1) && (bingo_result[3][i] == 1) &&
			(bingo_result[4][i] == 1))
		{

			return true;
		}
	}

	return false;
}




int calc_board_value(const vec2d& result, const vec2d& board)
{
	int score{  };
	for (int j = 0; j < board.size(); j++) // walk through lines
		for (int k = 0; k < board[j].size(); k++) // walk through ints
		{
			if (result[j][k] == 0)
			{
				score += board[j][k];

			}
		}

	return score;
}

bool check_if_all_boards(const std::vector<int>& boards_done)
{
	for (int i : boards_done)
	{
		if (i == 0) { return false; }
	}

	return true;
}


int play_bingo(Bingo_game& bingo, bool b)
{
	std::vector<vec2d> boards = bingo.get_boards();
	std::vector<vec2d>& bingo_results = bingo.get_results();
	std::vector<int>& boards_done = bingo.get_boards_done();


	for (int draw : bingo.get_numbers())
	{
		
		for (int i = 0; i < boards.size(); i++) // walk through boards
		{
			for (int j = 0; j < boards[i].size(); j++) // walk through lines
				for (int k = 0; k < boards[i][j].size(); k++) // walk through ints
				{
					if (draw == boards[i][j][k])
					{
						bingo_results[i][j][k] = 1;
						
					}
				}


			// Check if a win was found
			if (check_if_win(bingo_results[i]))
			{
				if (!b)
				{
					return draw * calc_board_value(bingo_results[i], boards[i]);
				}
				// b_val
				else
				{
					// Mark board as done
					// Check if all boards have been marked

					boards_done[i] = 1;

					if (check_if_all_boards(boards_done))
					{

						return draw * calc_board_value(bingo_results[i], boards[i]);
					}

				}
			}


		}

	}
	return -1;
}





void day_4_solver()
{
	// Start with reading the data.
	// First line contains the numbers that will be used for picking bingo numbers

	// Rest of text file is whitespace, 5 x 5 bingo board, ...

	Bingo_game bingo;

	bingo.read_file();

	
	
	
	int last_num = play_bingo(bingo, true);
	std::cout << last_num << '\n';



	
	

}