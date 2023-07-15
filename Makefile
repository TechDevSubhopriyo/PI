# Makefile for Creating the executable for Collision

# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

Collide: Collide.o
	$(CC) $(CFLAGS) -o test-output Collide.o

# The Collide.o target can be written more simply

Collide.o: Collide.cpp
	$(CC) $(CFLAGS) -c Collide.cpp

