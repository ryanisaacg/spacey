#include <iostream>
#include "spacey.h"

int main() {
	std::cout << apply_to_lines(line_to_spaces, "    a\n  b\n      c\n         d", 4);
	return 0;
}
