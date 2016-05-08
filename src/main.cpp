#include <iostream>
#include "spacey.h"

int main() {
	std::cout << line_to_spaces(line_to_tabs("\t\ta", 4), 4);
	return 0;
}
