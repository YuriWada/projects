CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -pg
OBJDIR = obj
BINDIR = bin
SRCDIR = src

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
MAIN = main.c
MAIN_OBJECT = $(OBJDIR)/main.o
TARGET = $(BINDIR)/pa3.out

all: $(TARGET)

$(TARGET): $(OBJECTS) $(MAIN_OBJECT)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/main.o: $(MAIN)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean
