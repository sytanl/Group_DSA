#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int command1(string algorithm, string input_file, string output_param, long long &input_size,  long long &count_assign, long long &count_compare, float &Time);
void output_for_command_1_2_3(string algorithm, string input_file, long long input_size, string output_param, long long count_compare, float Time);
void use_command1(string algorithm, string input_file, string output_param, long long &input_size,  long long &count_assign, long long &count_compare, float &Time);

#endif