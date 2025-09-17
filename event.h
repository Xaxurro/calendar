#ifndef H_CALENDAR_EVENT
#define H_CALENDAR_EVENT

#include "text_modifiers.h"
#include <chrono>
#include <regex>

using namespace std;
using namespace std::chrono;

enum Frequency {
	ONCE,
	DAILY,
	WEEKLY,
	BIWEEKLY,
	MONTHLY,
	YEARLY
};

struct Event {
	tm date;
	string description;
	Frequency frequency;
	Color color;
	unsigned char flags;
};

const regex regex_date("^\\s*(0?[1-9]|[12][0-9]|3[01])\\s+(0?[1-9]|1[0-2])\\s+(\\d{4})\\s*$");

tm  get_date_from_string(string* date_raw);

Event create_event(string* date_raw, string* description, Frequency* frequency, Color* color, unsigned char* flags);
void print_event(Event* event_ptr);

#endif // !H_CALENDAR_EVENT
