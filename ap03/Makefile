CC = gcc
CFLAGS = -Iinclude -Wall -g

SRC = src/fatorial.c src/fibo.c src/aux/aux.c main.c
OBJ = obj/fatorial.o obj/fibo.o obj/aux.o obj/main.o
BIN = bin/main.out

all: directories $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $^

obj/fatorial.o: src/fatorial.c
	$(CC) $(CFLAGS) -c $< -o $@

obj/fibo.o: src/fibo.c
	$(CC) $(CFLAGS) -c $< -o $@

obj/aux.o: src/aux/aux.c
	$(CC) $(CFLAGS) -c $< -o $@

obj/main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	mkdir -p obj bin

clean:
	rm -f obj/*.o bin/main.out
