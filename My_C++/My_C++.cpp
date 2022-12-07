#include <iostream>
#include "header1.h"

int main() {
	Box box1;
	Box box2(10.2, 20, 3.8);
	std::cout << box1.diagonal() << std::endl;
	std::cout << box2.volume(202102) << std::endl;
}