target := $1
CC := gcc
CFLAGS := -std=c11

build: $(target).c
	$(CC) $(CFLAGS) -o $(target) $(target).c

clean: *.exe
	rm *.exe
