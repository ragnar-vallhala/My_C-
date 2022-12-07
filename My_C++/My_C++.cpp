#include <iostream>
#include <string>
#include "header1.h"
extern int count;
int main() {
	std::string ne{ "vbkdvhdzvbizbvi" };
#ifdef DO_THIS
	print_this(ne);
#else
	print_that(ne);
#endif
	std::cout << count << std::endl;
}