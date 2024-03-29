
############################################
#  Author: 	Amber Rogowicz
#  File	:	Makefile  for building 
#  Date:	Aug 2019

CC = g++
# Note: the following are OSX platform flags
# CC = clang++
# CFLAGS  = -v -Wall -std=c++0x -ggdb -fPIC

# adjust flags as necessary for your platform
CFLAGS  = -Wall -fPIC -std=c++11 

LDFLAGS =  -lpthread

all: min_max_repeats.o  min_max_repeats sum_lowest_highest

min_max_repeats: min_max_repeats.o  
	$(CC) $(CFLAGS) $(LDFLAGS) min_max_repeats.o -o min_max_repeats

sum_lowest_highest: sum_lowest_highest.o  
	$(CC) $(CFLAGS) $(LDFLAGS) sum_lowest_highest.o -o sum_lowest_highest

min_max_repeats.o: min_max_repeats.cpp 
	$(CC) $(CFLAGS) -c min_max_repeats.cpp -o min_max_repeats.o

sum_lowest_highest.o: sum_lowest_highest.cpp 
	$(CC) $(CFLAGS) -c sum_lowest_highest.cpp -o sum_lowest_highest.o



clean:
	rm -rf *.o  min_max_repeats
