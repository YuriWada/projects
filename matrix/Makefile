CC = gcc
CFLAGS = -Iinclude -Wall -pg

SRC = src/matrix.c src/aux/aux.c main.c
OBJ = obj/matrix.o obj/aux.o obj/main.o
BIN = bin/main.out

all: directories $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $^

obj/aux.o: src/aux/aux.c
	$(CC) $(CLAFGS) -c $< -o $@

obj/matrix.o: src/matrix.c
	$(CC) $(CFLAGS) -c $< -o $@

obj/main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	mkdir -p obj bin

clean:
	rm -f obj/*.o bin/main.out