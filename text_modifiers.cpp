#include "text_modifiers.h"
#include "options.h"

#include <bitset>
#include <sstream>
#include <string>

using namespace std;

const char DELIMITER_CODE = ',';
const char ARGUMENT_CODE = '=';


string get_flag_code(Flags flag) {
	if (flag == Flags::BOLD) return "bold";
	if (flag == Flags::UNDERLINE) return "underline";
	if (flag == Flags::ITALIC) return "italic";
	if (flag == Flags::COLOR) return "color";
	return "none";
}

void check_for_flag(string* raw_flag_string, unsigned long* position_delimiter, unsigned char* flag_bitmask, Color* color_pointer) {
	unsigned long length_raw = raw_flag_string->length();
	// npos: no position
	if (*position_delimiter == string::npos) *position_delimiter = length_raw;
	string flag_code = raw_flag_string->substr(0, *position_delimiter);
	size_t length_code = flag_code.length();
	// Get the argument of the flag
	string argument;
	unsigned long position_argument = flag_code.find(ARGUMENT_CODE);
	if (position_argument != string::npos && position_argument < length_code) {
		argument = flag_code.substr(position_argument + 1, length_code);
		flag_code.erase(position_argument, length_code);
		Color new_color = get_color(argument);
		color_pointer->r = new_color.r;
		color_pointer->g = new_color.g;
		color_pointer->b = new_color.b;
	}
	// for each flag, if is a valid flag code, add it to the flag mask.
	for (const auto flag : flags) {
		if (flag_code.compare(get_flag_code(flag)) == 0) {
			*flag_bitmask |= flag;
			break;
		}
	}
	// eat a bite from the string
	raw_flag_string->erase(0, *position_delimiter);
	if (raw_flag_string->length() != length_raw) raw_flag_string->erase(0,1);
}

// Turns a string formatted like "[...]" where "..." is a valid modifier string, the pointer updates it's values if color is selected
unsigned char get_flags(string raw_flag_string, Color* color_pointer) {
	if (raw_flag_string.length() <= 2) return 0;
	raw_flag_string.erase(0,1);
	raw_flag_string.erase(raw_flag_string.length() - 1);

	// return variable
	unsigned char flag_bitmask = 0;
	unsigned long position_delimiter = 1;
	while(position_delimiter != 0) {
		position_delimiter = raw_flag_string.find(DELIMITER_CODE);
		check_for_flag(&raw_flag_string, &position_delimiter, &flag_bitmask, color_pointer);
	}
	return flag_bitmask;
}

// Turns a string formatted like "FFFFFF" where F is a valid hex char into a `color` struct
Color color_from_string(string hex) {
	Color new_color;
	unsigned int temporal_value;
	// Grabs 2 hex characters, parses it to unsigned char, and store it on he struct's `r`, `g`, and `b` respectively
	stringstream(hex.substr(0, 2)) >> std::hex >> temporal_value;
	new_color.r = temporal_value;

	stringstream(hex.substr(2, 2)) >> std::hex >> temporal_value;
	new_color.g = temporal_value;

	stringstream(hex.substr(4, 2)) >> std::hex >> temporal_value;
	new_color.b = temporal_value;
	return new_color;
}

// Returns a ansi code based on the `color` struct given
string ansi_code_from_color(Color* color) {
	string ansi_code = "\x1B[38;2;";
	ansi_code += to_string(color->r) + ";";
	ansi_code += to_string(color->g) + ";";
	ansi_code += to_string(color->b) + "m";
	return ansi_code;
}

// Returns the literal bit in said position
unsigned int get_bit(unsigned char flags, char position) {
	return (flags & (1 << position)) >> position;
}
// Returns a ansi code based on the flag given
string ansi_code_from_flag(unsigned char flags) {
	string ansi_code;
	if (get_bit(flags, 0)) ansi_code += "\x1B[1m";
	if (get_bit(flags, 1)) ansi_code += "\x1B[4m";
	if (get_bit(flags, 2)) ansi_code += "\x1B[3m";
	return ansi_code;
}
