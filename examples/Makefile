# Variables
CC = gcc
LDLIBS = -lGL -lglfw -lm
SRC ?= window

.PHONY: all clean

# Compiling application
all:
	$(CC) $(SRC).c $(LDLIBS) -o $(SRC)

clean:
	find . -type f -executable -delete
