CC      = gcc
CFLAGS  = -Wall -Wextra -Iinclude
TARGET  = heapster
SRCS    = $(wildcard src/*.c)
OBJS    = $(SRCS:.c=.o)

all: build

build: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: build
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all build run clean
