C = g++

all: calendar.bin

calendar.bin: text_modifiers.o options.o event.o
	$(C) main.cpp text_modifiers.o options.o event.o -o calendar.bin

event.o: text_modifiers.o options.o
	$(C) -c event.cpp -o event.o

options.o: text_modifiers.o
	$(C) -c options.cpp -o options.o

text_modifiers.o:
	$(C) -c text_modifiers.cpp -o text_modifiers.o

clear:
	rm *.o *.bin
