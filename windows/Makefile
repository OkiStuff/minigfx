# Variables
CC = gcc
LDLIBS ?= -L lib/ -lglfw3 -lopengl32 -lgdi32 -lwinmm
INCLUDE ?= -I include/
SRC ?= examples/window

.PHONY: all clean

# Compiling application
all:
	$(CC) $(SRC).c $(INCLUDE) $(LDLIBS) -o $(SRC).exe

clean:
	del *.exe
