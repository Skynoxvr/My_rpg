##
## EPITECH PROJECT, 2024
## B-MUL-200-MPL-2-1-myrpg-ethan.furia [WSL: Ubuntu-22.04]
## File description:
## Makefile
##

CFLAGS = -Wall -Wextra
LIBFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

TARGET = my_rpg

SRC = $(wildcard src/*.c) $(wildcard src/*/*.c)

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) -g3 $(OBJ) $(LIBFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
