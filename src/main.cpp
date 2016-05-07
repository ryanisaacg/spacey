#include <iostream>
#include <fstream>
#include <string>

std::string line_to_tabs(const std::string input, const unsigned int spaces_per) {
	std::string new_str = "";
	unsigned int running_spaces = 0;
	bool finished_whitespace = false;
	unsigned int i;
	for(i = 0; i < input.length() && !finished_whitespace; i++) {
		char current = input.at(i);
		switch(current) {
		case ' ':
			running_spaces++;
			if(running_spaces == spaces_per) {
				running_spaces = 0;
				new_str += '\t';
			}
			break;
		case '\t':
			if(running_spaces > 0) {
				running_spaces = 0;
				new_str += '\t';
			}
			new_str += '\t';
			break;
		default:
			finished_whitespace = true;
			i--;
			break;
		}
	}
	if(running_spaces > 0)
		new_str += '\t';
	new_str += input.substr(i);
	return new_str;
}

int main() {
	std::cout << line_to_tabs("  \ta  ", 4);
	return 0;
}
