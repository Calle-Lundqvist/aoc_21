#include "day_2.h"



class Sub
{
private:
	int h{};
	int d{};
	int a{};

public:
	Sub(int horizontal = 0, int depth = 0, int aim = 0)
		: h{ horizontal }, d{ depth }, a{ aim }
	{}

	int get_h() { return h; };
	int get_d() { return d; };
	int get_a() { return a; };

	void update_h(int num)
	{
		h += num;
	}
	void update_d(int num)
	{
		d += num;
	}
	void update_a(int num)
	{
		a += num;
	}

	void sub_status()
	{
		std::cout << "Aim is " << a << ". Depth is " << d << " and horizontal position is " << h << ". Product of these is " << d * h << '\n';
	}
};


void move_sub_a(Sub &sub)
{
	std::fstream newfile;
	std::string file_path{ "input_data\\day_2_data.txt" };
	newfile.open(file_path, std::ios::in); // open file for reading

	if (!newfile) std::cerr << "Could not open the file!" << std::endl;

	if (newfile.is_open())
	{
		std::string line{};
		while (std::getline(newfile, line))
		{
			
			std::vector<std::string> words{ split_string_by_delim(line, ' ') };
			
			// Move the sub according to commands given in words. 
			if (words[0] == "forward")
			{
				sub.update_h(std::stoi(words[1])); // Move forward words[1] steps
			}
			else if (words[0] == "down")
			{
				sub.update_d(std::stoi(words[1])); // INCREASE depth by words[1]
			}
			else
			{
				sub.update_d(-std::stoi(words[1])); // DECREASE depth by words[1]
			}

		}
		newfile.close();
	}

}

void move_sub_b(Sub& sub)
{
	std::fstream newfile;
	std::string file_path{ "input_data\\day_2_data.txt" };
	newfile.open(file_path, std::ios::in); // open file for reading

	if (!newfile) std::cerr << "Could not open the file!" << std::endl;

	if (newfile.is_open())
	{
		std::string line{};
		while (std::getline(newfile, line))
		{

			std::vector<std::string> words{ split_string_by_delim(line, ' ') };

			// Move the sub according to commands given in words. 
			if (words[0] == "forward")
			{
				sub.update_h(std::stoi(words[1]));						// Move forward words[1] steps
				sub.update_d(sub.get_a() * std::stoi(words[1]));		// Increases depth by AIM multiplied by words[1]
			}
			else if (words[0] == "down")
			{
				sub.update_a(std::stoi(words[1]));						// INCREASE aim by words[1]
			}
			else
			{
				sub.update_a(-std::stoi(words[1]));						// DECREASE aim by words[1]
			}
			// sub.sub_status();
		}
		newfile.close();
	}

}


void day_2_solver()
{
	Sub sub{};

	// move_sub_a(sub);
	move_sub_b(sub);

	sub.sub_status();

}
