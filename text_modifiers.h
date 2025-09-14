#ifndef H_CALENDAR_COLOR
#define H_CALENDAR_COLOR

#include <cstdint>
#include <iostream>

enum Flags {
	NONE,
	BOLD,
	UNDERLINE,
	ITALIC,
	COLOR
};

static const Flags flags[] = {BOLD, UNDERLINE, ITALIC, COLOR};

struct Color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

std::string get_flag_code(Flags flag);
unsigned char get_flags(std::string modifiers, Color* resulting_color);

Color color_from_string(std::string hex);
std::string ansi_code_from_color(Color* color);
std::string ansi_code_from_flag(unsigned char flags);

#endif // !H_CALENDAR_COLOR
