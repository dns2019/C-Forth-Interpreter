CC = gcc
CFLAGS = -g -Wall
C_FILES = $(wildcard src/*.c)
H_FILES = $(wildcard src/*.h)
BUILD = interpreter

.PHONY = all install clean

$(BUILD): $(C_FILES) $(H_FILES)
	        $(CC) $(CFLAGS) $(C_FILES) -o $@

all: $(BUILD)

