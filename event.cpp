#include "event.h"
#include "text_modifiers.h"
using namespace std;

int get_date_from_string(string* date_raw, tm* date_ptr) {
	smatch captured_groups;

	if (!regex_match(*date_raw, captured_groups, regex_date)) {
		return 1;
	}

	date_ptr->tm_mday = stoi(captured_groups[1]);
	date_ptr->tm_mon = stoi(captured_groups[2]);
	date_ptr->tm_year = stoi(captured_groups[3]);
	return 0;
}

Event create_event(string* date_raw, string* description, Frequency* frequency, Color* color, unsigned char* flags) {
	Event event;
	tm date;
	int error = get_date_from_string(date_raw, &date);
	if (error == 1) return {};

	event.date = date;
	event.description = *description;
	event.frequency = *frequency;
	event.color = *color;
	event.flags = *flags;
	return event;
}

void print_event(Event* event_ptr) {
	cout << ansi_code_from_color(&event_ptr->color) << ansi_code_from_flag(event_ptr->flags) << event_ptr->description << "\x1b[0m" << endl;
}
