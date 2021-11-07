.PHONY: all clean
.DEFAULT_GOAL := all

test_dir := ./logs
$(shell if [ ! -e $(test_dir) ];then mkdir -p $(test_dir); fi)

LIBS=-lglog -lgflags
INCLUDES=-I./include
CFLAGS=-O3 -std=c++11 -g 

output = task

all: main

main: ./src/task.cpp
	g++ $(CFLAGS) -o task ./src/task.cpp $(LIBS)

clean: 
	rm -rf $(output) input *.dSYM
