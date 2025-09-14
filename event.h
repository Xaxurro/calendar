#ifndef H_CALENDAR_EVENT
#define H_CALENDAR_EVENT

#include "text_modifiers.h"
#include <chrono>

using namespace std;

enum Frequency {
	ONCE,
	DAILY,
	WEEKLY,
	BIWEEKLY,
	MONTHLY,
	YEARLY
};

struct Event {
	chrono::time_point<chrono::steady_clock> date;
	string description;
	Frequency f;
	Color c;
	unsigned char flags;
};

#endif // !H_CALENDAR_EVENT
