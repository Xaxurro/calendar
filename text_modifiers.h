#ifndef H_CALENDAR_COLOR
#define H_CALENDAR_COLOR

#include <cstdint>
#include <iostream>

enum FLAGS {
	NONE = 0,
	BOLD = 1,
	UNDERLINE = 2,
	ITALIC = 4,
	COLOR = 8
};

static const FLAGS flags[] = {BOLD, UNDERLINE, ITALIC, COLOR};

struct color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

std::string get_flag_code(FLAGS flag);
unsigned char get_flags(std::string modifiers, color* resulting_color);

color color_from_string(std::string hex);
std::string ansi_code_from_color(color* color);
std::string ansi_code_from_flag(unsigned char flags);

#endif // !H_CALENDAR_COLOR
