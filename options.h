#ifndef H_CALENDAR_OPTIONS
#define H_CALENDAR_OPTIONS

#include "text_modifiers.h"

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std::filesystem;

enum OPTIONS {
	HELP,
	TIME_FUTURE,
	TIME_PAST
};

enum COMMANDS {
	EVENTS,
	CALENDAR
};

path get_path();
void create_path();
void set_color(std::string id, std::string value);
color get_color(std::string id);

#endif // !H_CALENDAR_OPTIONS
