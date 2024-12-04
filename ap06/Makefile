CC = gcc
CFLAGS = -Iinclude -Wall -g

SRC = src/heap.c pa6.c
OBJ = obj/heap.o obj/pa6.o
BIN = bin/pa6.out

all: diretories $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $^

obj/heap.o: src/heap.c
	$(CC) $(CFLAGS) -c $< -o $@

obj/pa6.o: pa6.c
	$(CC) $(CFLAGS) -c $< -o $@

diretories:
	mkdir -p obj bin

clean:
	rm -f obj/*.o bin/pa6.out
