#ifndef SPACEY_H_
#define SPACEY_H_
#include <string>

/*
Convert a line of text from spaces or a mix to tab-only
Useful for the guarantee that a line will be indented with tabs
Pure function
*/
const std::string line_to_tabs(const std::string input, const unsigned int spaces_per);

const std::string line_to_spaces(const std::string input, const unsigned int spaces_per);

const std::string apply_to_lines(const std::string (*convert)(const std::string, const unsigned int),
const std::string input, const unsigned int spaces_per);
#endif
