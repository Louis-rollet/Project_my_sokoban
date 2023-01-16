##
## EPITECH PROJECT, 2022
## B-PSU-100-MPL-1-1-myls-louis.rollet
## File description:
## Makefile
##

CC = gcc
SRC = $(wildcard *.c)
TARGET = my_sokoban
OBJ = $(wildcard *~)

$(TARGET) :
	$(CC) -o $(TARGET) $(SRC) -lncurses -g3

all :	$(TARGET)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(TARGET)

re : fclean all
