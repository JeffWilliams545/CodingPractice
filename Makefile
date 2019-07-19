# Define required macros here
SHELL = /bin/sh

CFLAG = -Wall -g
CC = g++
INCLUDE =
LIBS = -lm

all: hello_world basic_datatypes conditionals for_loop input_sum menu tweakLetters rpg_framework
.PHONY: all

hello_world: hello_world.cpp
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@

basic_datatypes: basic_datatypes.cpp
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@

conditionals: conditionals.cpp
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@

for_loop: for_loop.cpp 
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@

input_sum: input_sum.cpp 
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@

menu: menu.cpp
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@

tweakLetters: tweakLetters.cpp
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@

rpg_framework: rpg_framework.cpp rpg_framework.h
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@

clean:
	-rm -f *.o core *.core hello_world basic_datatypes conditionals for_loop input_sum menu tweakLetters rpg_framework

.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
