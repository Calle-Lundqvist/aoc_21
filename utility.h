#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::string get_file_path(std::string day, bool real);

std::vector<int> read_line_ints_from_file(std::string, bool);

std::vector<std::vector<int>> read_2dVec_ints_from_file(std::string day, bool real);

std::vector<std::string> split_string_by_delim(std::string str, char delim);

int64_t binaryToDecimal(std::string s);