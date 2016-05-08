#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "spacey.h"

const std::string helptext = "Enter spaces or tabs and the number of spaces per tab, followed by one or more files.\n";

int main(int argc, char *argv[]) {
	if(argc < 3) {
		std::cout << helptext;
		return 1;
	}
	bool spaces = strcmp("spaces", argv[1]) == 0;
	bool tabs = strcmp("tabs", argv[1]) == 0;
	if(!spaces && !tabs) {
		std::cout << helptext;
		return 2;
	}
	auto function = line_to_tabs;
	if(spaces) {
		function = line_to_spaces;
	}
	int spaces_per = std::stoi(argv[2]);
	for(int i = 3; i < argc; i++) {
		const std::string converted = apply_to_file(function, argv[i], spaces_per);
		std::ofstream output (argv[i]);
		output << converted;
		output.close();
	}
	return 0;
}
