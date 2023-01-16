/*
** EPITECH PROJECT, 2022
** B-PSU-100-MPL-1-1-sokoban-louis.rollet
** File description:
** coord_player
*/
#include "my.h"

void coor_player(char **map, t_coordinate *coord, int i, int j)
{
    if (map[i][j] == 'P') {
        coord->y_player = i;
        coord->x_player = j;
    }
    if (map[i][j] == 'O'){
        coord->circle[coord->x][0] = i;
        coord->circle[coord->x][1] = j;
        coord->x++;
    }
}

int while_if_buff(char **buff, int i)
{
    for (int j = 0; buff[i][j] != '\0'; j++) {
        mvprintw(i, j, "%c", buff[i][j]);
    }
}

int start_game(int argc, char **argv)
{
    initscr();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    int temp1 = 0;
    int temp2 = 0;
    struct s_coordinate coord;
    coord.circle = malloc(sizeof(int) * 100);
    for (int i = 0; i < 100; i++) {
        coord.circle[i] = malloc(sizeof(int) * 2);
    }
    getmaxyx(stdscr, temp1, temp2);
    char **tabl = load_file_in_str(argv[1]);
    coord.buff_save = load_file_in_str(argv[1]);
    get_width_hight(&coord, tabl);
    verif_player_coor(tabl, &coord);
    while_true(temp1, temp2, &coord, tabl);
    free(tabl);
}
