C = g++

all: options.o

options.o: text_modifiers.o
	$(C) options.cpp text_modifiers.o -o options.o

text_modifiers.o:
	$(C) -c text_modifiers.cpp -o text_modifiers.o

clear:
	rm *.o
