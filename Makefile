#NOTE: This is for mac only right now. Will create a makefile for linux and windows later
CC     := gcc
TARGET := build/sim
SRC    := $(wildcard src/*.c)
OBJ    := $(SRC:src/%.c=build/%.o)
DEP    := $(OBJ:.o=.d)

RAYLIB := $(shell brew --prefix raylib)

CFLAGS  := -Wall -Wextra -g -Iinclude -I$(RAYLIB)/include -MMD -MP
LDFLAGS := -L$(RAYLIB)/lib
LDLIBS  := -lraylib -lm -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

run: all
	./$(TARGET)

clean:
	rm -rf build

-include $(DEP)

.PHONY: all run clean
