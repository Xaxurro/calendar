#include "options.h"
#include "text_modifiers.h"
#include <bitset>
#include <string>

using namespace std;

unordered_map<string, string> colors;

// `path` MUST be a path to the main file
// Sets `path` to $HOME/calendar if `$CALENDAR_PATH` is empty
filesystem::path get_path() {
	filesystem::path path = getenv("CALENDAR_PATH");
	if (path.empty()) path = strcat(getenv("HOME"), "/calendar/main.cldr");
	return path;
}

void create_path() {
	filesystem::path path = get_path();
	bool path_exists = filesystem::is_directory(path.parent_path());
	if (!path_exists) filesystem::create_directory(path.parent_path());
}

void set_color(string id, string value) {
	colors[id] = value;
}

Color get_color(string id) {
	return color_from_string(colors[id]);
}
