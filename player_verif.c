/*
** EPITECH PROJECT, 2022
** B-PSU-100-MPL-1-1-sokoban-louis.rollet
** File description:
** player_verif
*/
#include "my.h"

int verif_player_coor(char **map, t_coordinate *coord)
{
    coord->x = 0;
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            coor_player(map, coord, i, j);
        }
    }
    coord->circle[coord->x][0] = -1;
    coord->x_player_save = coord->x_player;
    coord->y_player_save = coord->y_player;
}

int verif_char(char **buff, t_coordinate *coord, int x, int y)
{
    if (buff[coord->y_player + y][coord->x_player + x] != '#' &&
    buff[coord->y_player + y][coord->x_player + x] != 'X')
        return 1;
    return 0;
}

int verif_char_2(char **buff, t_coordinate *coord, int x, int y)
{
    if (buff[coord->y_player + y][coord->x_player + x] != '#' &&
    buff[coord->y_player + y][coord->x_player + x] != 'X')
        return 1;
    return 0;
}

int big_if(int row, int col, char **buff)
{
    werase(stdscr);
    int temp1 = row;
    int temp2 = col;
    for (int i = 0; buff[i] != NULL; i++) {
        for (int j = 0; buff[i][j] != '\0'; j++) {
            mvprintw(i, j, "%c", buff[i][j]);
        }
    }
}

int resize_col(int row, int col, t_coordinate *coord)
{
    char *error = "Please resize your terminal";
    if (row < coord->hight + 1 || col < coord->width + 1){
        werase(stdscr);
        mvprintw(row / 2, col / 2 - my_strlen(error) / 2, error);
    }
}
