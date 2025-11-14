CC = gcc
FLAGS = -Wall -Werror
UTILS = wcat

all: $(UTILS)

mcat: wcat.c
	$(CC) wcat.c -o wcat $(FLAGS)

clean:
	rm -f $(UTILS)	