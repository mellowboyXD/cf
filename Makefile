target := $1
CC := gcc
CFLAGS := -std=c11

all: build
	echo "==="

build: $(target).c
	$(CC) $(CFLAGS) -o $(target) $(target).c

clean: *.exe
	rm *.exe
