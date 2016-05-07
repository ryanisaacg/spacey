#include <iostream>
#include <fstream>
#include <string>

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

int main() {
	std::cout << line_to_spaces(line_to_tabs("\t\ta", 4), 4);
	return 0;
}
