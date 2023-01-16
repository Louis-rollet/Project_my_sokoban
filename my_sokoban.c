/*
** EPITECH PROJECT, 2022
** B-PSU-100-MPL-1-1-sokoban-louis.rollet
** File description:
** my_sokoban
*/
#include "my.h"

void verif_x(t_coordinate *coord, char **buff, int x, int y)
{
    if (buff[coord->y_player + y][coord->x_player + x] == 'X') {
        if (verif_char_2(buff, coord, 2 * x, 2 * y) == 1) {
            buff[coord->y_player][coord->x_player] = ' ';
            buff[coord->y_player + y][coord->x_player + x] = 'P';
            buff[coord->y_player + 2 * y][coord->x_player + 2 * x] = 'X';
            coord->x_player += x;
            coord->y_player += y;
        }
    }
    if (verif_char(buff, coord, x, y)){
        buff[coord->y_player][coord->x_player] = ' ';
        buff[coord->y_player + y][coord->x_player + x] = 'P';
        coord->x_player += x;
        coord->y_player += y;
    }
}

int verif_event_2(int c, t_coordinate *coord, char **buff)
{
    if (c == ' '){
        replace_map(buff, coord);
        coord->x_player = coord->x_player_save;
        coord->y_player = coord->y_player_save;
    }
    if (c == KEY_BACKSPACE){
        werase(stdscr);
        endwin();
        exit(0);
    }
}

int verif_event(int c, t_coordinate *coord, char **buff)
{
    int a = 0;
    int i = 0;
    if (c == KEY_UP)
        verif_x(coord, buff, 0, -1);
    if (c == KEY_DOWN)
        verif_x(coord, buff, 0, 1);
    if (c == KEY_LEFT)
        verif_x(coord, buff, -1, 0);
    if (c == KEY_RIGHT)
        verif_x(coord, buff, 1, 0);
    for (; coord->circle[i][0] != -1; i++) {
        if (buff[coord->circle[i][0]][coord->circle[i][1]] == ' ')
            buff[coord->circle[i][0]][coord->circle[i][1]] = 'O';
        if (buff[coord->circle[i][0]][coord->circle[i][1]] == 'X')
            a++;
    }
    if (a == i)
        return 0;
    verif_event_2(c, coord, buff);
    return 1;
}

int while_true(int temp1, int temp2, t_coordinate *coord, char **buff)
{
    int row = 0;
    int col = 0;
    int c = 0;
    int w = 1;
    while (w == 1){
        c = getch();
        getmaxyx(stdscr,row,col);
        w = verif_event(c, coord, buff);
        for (int i = 0; buff[i] != NULL; i++) {
            while_if_buff(buff, i);
        }
        mvprintw(coord->hight + 1, 0," ");
        if (temp1 != row || temp2 != col){
            big_if(row, col, buff);
        }
        resize_col(row, col, coord);
        refresh();
    }
    endwin();
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h'){
        write(1, "USAGE\n     ./my_sokoban map\nDESCRIPTION\n", 40);
        write(1, "     ", 5);
        write(1,"map file representing the warehouse map", 39);
        write(1, "containing '#' for walls,\n", 26);
        write(1, "         ", 9);
        write(1,"'P' for the player,", 65);
        write(1," 'X' for boxes and 'O' for storage locations.\n", 46);
        return 0;
    } else {
        if (open(argv[1], O_RDONLY) == -1)
            return 84;
        start_game(argc, argv);
        return 0;
    }
}
