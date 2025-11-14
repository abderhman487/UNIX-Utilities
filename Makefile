CC = gcc
FLAGS = -Wall -Werror
UTILS = wcat wgrep

all: $(UTILS)

wcat: wcat.c
	$(CC) wcat.c -o wcat $(FLAGS)
wgrep: wgrep.c
	$(CC) wgrep.c -o wgrep $(FLAGS)

clean:
	rm -f $(UTILS)