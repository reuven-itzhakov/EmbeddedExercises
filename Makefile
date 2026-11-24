CC = gcc
CFLAGS = -Wall -g

DIRS ?= exMod
SRCS := $(wildcard $(addsuffix /*.c,$(DIRS)))

TARGETS := $(SRCS:.c=)

.PHONY: all clean

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)