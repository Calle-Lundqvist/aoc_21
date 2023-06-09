#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>     /* abs */

std::string get_file_path(std::string, bool);

std::vector<int> read_line_ints_from_file(std::string, bool);

std::vector<std::string> read_all_strings_from_file(std::string, bool);

std::vector<std::vector<int>> read_2dVec_ints_from_file(std::string, bool);

std::vector<std::string> split_string_by_delim(std::string, char);
std::vector<std::string> split_string_by_delim(std::string, std::string);

std::vector<int> split_string_by_delim_return_int(std::string, char);

std::vector<int> split_string_by_space_return_int(std::string);

int64_t binaryToDecimal(std::string);

bool check_if_diagonal(int, int, int, int);