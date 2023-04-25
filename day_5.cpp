#include "day_5.h"


class Vec2d
{
public:
	std::vector<std::vector<int>> elems{};


	void initialize(int x_len, int y_len)
	{
		std::vector<std::vector<int>> all{};

		for (int i = 0; i < y_len; i++)
		{

			std::vector<int> init_x(x_len, 0);
			all.push_back(init_x);

		}
		elems = all;
	}


	void status()
	{
		for (std::vector<int> row : elems)
		{
			for (int i : row)
			{
				std::cout << i << ' ';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}


	int num_danger_points(int danger_value)
	{
		int danger_points{ 0 };

		for (std::vector<int> rows : elems)
		{
			for (int x : rows)
			{
				if (x >= danger_value)
				{
					danger_points++;
				}
			}
		}

		return danger_points;
	}

};







void day_5_solver()
{
	
	std::vector<std::string> input_data{ read_all_strings_from_file("5", true) };

	std::vector<int> x1_vals{};
	std::vector<int> y1_vals{};
	std::vector<int> x2_vals{};
	std::vector<int> y2_vals{};

	for (std::string line : input_data)
	{
		std::vector<std::string> split = split_string_by_delim(line, "->");

		std::vector<int> pos1 = split_string_by_delim_return_int(split[0], ',');
		x1_vals.push_back(pos1[0]);
		y1_vals.push_back(pos1[1]);

		std::vector<int> pos2 = split_string_by_delim_return_int(split[1], ',');
		x2_vals.push_back(pos2[0]);
		y2_vals.push_back(pos2[1]);

	}

	int x1_max = *std::max_element(x1_vals.begin(), x1_vals.end());
	int x1_min = *std::min_element(x1_vals.begin(), x1_vals.end());
	int y1_max = *std::max_element(y1_vals.begin(), y1_vals.end());
	int y1_min = *std::min_element(y1_vals.begin(), y1_vals.end());

	int x2_max = *std::max_element(x2_vals.begin(), x2_vals.end());
	int x2_min = *std::min_element(x2_vals.begin(), x2_vals.end());
	int y2_max = *std::max_element(y2_vals.begin(), y2_vals.end());
	int y2_min = *std::min_element(y2_vals.begin(), y2_vals.end());

	if (x2_max > x1_max) { x1_max = x2_max; }
	if (y2_max > y1_max) { y1_max = y2_max; }
	if (x2_min < x1_min) { x1_min = x2_min; }
	if (y2_min < y1_min) { y1_min = y2_min; }

	int x_len = x1_max - x1_min;
	int y_len = y1_max - y1_min;

	Vec2d vec2d;
	vec2d.initialize(x_len + 20, y_len + 20);

	


	for (int i = 0; i < x1_vals.size(); i++)
	{
		int low{};
		int high{};
		if (x1_vals[i] == x2_vals[i])
		{
			// Walk through y vals
			if (y1_vals[i] > y2_vals[i]){ high = y1_vals[i]; low = y2_vals[i]; }
			else{ high = y2_vals[i]; low = y1_vals[i]; }

			for (int y = low; y <= high; y++)
			{
				vec2d.elems[y][x1_vals[i]] += 1;
			}
		}
		else if ((y1_vals[i] == y2_vals[i]))
		{
			// Walk through x vals
			if (x1_vals[i] > x2_vals[i]) { high = x1_vals[i]; low = x2_vals[i]; }
			else{ high = x2_vals[i]; low = x1_vals[i]; }

			for (int x = low; x <= high; x++)
			{
				vec2d.elems[y1_vals[i]][x] += 1;
			}
		}
		else if (check_if_diagonal(x1_vals[i], y1_vals[i], x2_vals[i], y2_vals[i]))
		{
			
			int num_steps = abs(x2_vals[i] - x1_vals[i]);
			

			int x_step{};
			if (x1_vals[i] > x2_vals[i]){ x_step = 1; }
			else { x_step = -1; }

			int y_step{};
			if (y1_vals[i] > y2_vals[i]){ y_step = 1; }
			else { y_step = -1; }

			int x = x2_vals[i];
			int y = y2_vals[i];
			for (int j = 0; j <= num_steps; j++)
			{
				vec2d.elems[y][x] += 1;
				x += x_step;
				y += y_step;
			}
		}
		
	}

	//vec2d.status();


	std::cout << vec2d.num_danger_points(2);;

}