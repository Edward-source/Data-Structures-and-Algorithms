# -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#  Simple makefile for multitarget build systems
#
#  User: make [targets] [overrides]
#
#  Targets:
#       <FILE>.o  - Builds <FILE>. object file
#       build - Builds and links all source files
#       all   -  Same as build
#       clean - Removes all generated files
#
#  Overrides:
#       CPU   - ARM Cortex Architecture (cortex-m0plus, context-m4)
#       ARCH  - ARM Architecture (arm, thumb)
#       SPECS - Specs file to give the linker (nosys.specs, nano.specs)
#
#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Set the compiler to use to gcc
CC=gcc

# Set compiler flags to enable warnings as errors
CFLAGS=-Wall -Werror

# Default target - build my_program
all: solution

# Target to build the executable
solution: main.o speed.o acceleration.o
	$(CC) $(CFLAGS) -o solution main.o speed.o acceleration.o

# Target to compile main.c to an object file
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Target to compile speed.c to an object file
speed.o: speed.c
	$(CC) $(CFLAGS) -c speed.c

# Target to compile acceleration.c to an object file
acceleration.o: acceleration.c
	$(CC) $(CFLAGS) -c acceleration.c

# Target to clean up generated files
clean:
	rm -rf solution 
	rm -rf *.o
	rm -rf *.out
