CC = gcc
FLAGS = -Wall -Werror
UTILS = wcat wgrep wzip

all: $(UTILS)

wcat: wcat.c
	$(CC) wcat.c -o wcat $(FLAGS)
wgrep: wgrep.c
	$(CC) wgrep.c -o wgrep $(FLAGS)
wzip: wzip.clean
	$(CC) wzip.c -o wzip $(FLAGS)
	
clean:
	rm -f $(UTILS)