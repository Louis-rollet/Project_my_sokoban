/*
** EPITECH PROJECT, 2022
** B-PSU-100-MPL-1-1-sokoban-louis.rollet
** File description:
** my
*/
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef MY_H_
    #define MY_H_

typedef struct s_coordinate{
    int x_player;
    int y_player;
    int x_player_save;
    int y_player_save;
    int width;
    int hight;
    int **circle;
    int x;
    char **buff_save;
} t_coordinate;

char **load_caractere(char **tabl, char *str);
char **load_2d_tabl(char *str);
char ** load_file_in_str(char const * filepath);
int verif_player_coor(char **map, t_coordinate *coord);
int verif_char(char **buff, t_coordinate *coord, int x, int y);
int verif_char_2(char **buff, t_coordinate *coord, int x, int y);
int big_if(int row, int col, char **buff);
int resize_col(int row, int col, t_coordinate *coord);
int get_width_hight(t_coordinate *coord, char **buff);
void coor_player(char **map, t_coordinate *coord, int, int);
int while_if_buff(char **buff, int i);
void replace_map(char **buff, t_coordinate *coord);
int start_game(int argc, char **argv);

#endif /* !MY_H_ */
