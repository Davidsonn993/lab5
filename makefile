# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = main
SRC = main.c double_list.c
OBJ = $(SRC:.c=.o)

# Reglas
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

# Phony targets
.PHONY: all clean
