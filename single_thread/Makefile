.PHONY: all clean
.DEFAULT_GOAL := all

CFLAGS=-O3 -std=c++11 -g 

output = task

all: main

main: ./src/task.cpp
	g++ $(CFLAGS) -o task ./src/task.cpp $(LIBS)

clean: 
	rm $(output)
