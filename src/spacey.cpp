#include "spacey.h"
#include <fstream>

/*
Convert a line of text from spaces or a mix to tab-only
Useful for the guarantee that a line will be indented with tabs
Pure function
*/
const std::string line_to_tabs(const std::string input, const unsigned int spaces_per) {
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
	if(running_spaces > 0) //If there are three trailing spaces on an indent, there should be a tab
		new_str += '\t';
	new_str += input.substr(i); //Put the actual line contents into the string
	return new_str;
}

const std::string line_to_spaces(const std::string input, const unsigned int spaces_per) {
	const std::string tabs_only = line_to_tabs(input, spaces_per); //Tabs for consistency
	std::string new_str = "";
	std::string tabbed_size = "";
	unsigned int i;
	for(i = 0; i < spaces_per; i++)
		tabbed_size += " ";
	for(i = 0; i < tabs_only.length(); i++)
	{
		if(tabs_only.at(i) == '\t')
			new_str += tabbed_size;
		else
			break;
	}
	new_str += tabs_only.substr(i);
	return new_str;
}

const std::string apply_to_lines(const std::string (*convert)(const std::string, const unsigned int),
const std::string input, const unsigned int spaces_per) {
	unsigned int begin = 0, end = 0;
	std::string converted = "";
	for(unsigned int i = 0; i < input.length(); i++) {
		end++;
		if(input.at(i) == '\n') {
			converted += convert(input.substr(begin, end), spaces_per);
			begin = end;
		}
	}
	converted += convert(input.substr(begin, end), spaces_per);
	return converted;
}

//TODO:
const std::string apply_to_file(const std::string (*convert)(const std::string, const unsigned int),
const std::string filename, const unsigned int spaces_per) {
	std::string line;
	std::string value = "";
	std::ifstream file(filename);
	if(file.is_open()) {
		while(std::getline(file, line)) {
			value += convert(line, spaces_per) + "\n";
		}
		file.close();
	} else {
		return "File not found.";
	}
	return value;
}
