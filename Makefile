CC = gcc
FLAGS = -Wall -Werror
UTILS = wcat wgrep wzip wunzip

all: $(UTILS)

wcat: wcat.c
	$(CC) wcat.c -o wcat $(FLAGS)
wgrep: wgrep.c
	$(CC) wgrep.c -o wgrep $(FLAGS)
wzip: wzip.c
	$(CC) wzip.c -o wzip $(FLAGS)
wunzip: wunzip.c
	$(CC) wunzip.c -o wunzip $(FLAGS)

clean:
	rm -f $(UTILS)