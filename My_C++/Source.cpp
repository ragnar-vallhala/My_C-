#include "header1.h"
#include <iostream>

int count{ 0 };
void print1::print(std::string& str) {
	std::cout << str <<"\tprint1" << std::endl;
	count++;
}
void print2::print(std::string& str) {
	std::cout << str << "\tprint2" << std::endl;
	count++;
}

void print_that(std::string& str) {
	print1::print(str);
}
void print_this(std::string& str) {
	print2::print(str);
}