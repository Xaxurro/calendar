#include <iostream>
#include "event.h"
using namespace std;

int main (int argc, char *argv[]) {
	string date_raw = "08 11 2002";
	string description = "description";
	Frequency frequency = Frequency::DAILY;
	Color color = {255,0,0};
	unsigned char flags = 1;

	Event event = create_event(&date_raw, &description, &frequency, &color, &flags);
	print_event(&event);
	return 0;
}
