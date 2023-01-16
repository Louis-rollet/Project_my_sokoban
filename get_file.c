/*
** EPITECH PROJECT, 2022
** B-PSU-100-MPL-1-1-sokoban-louis.rollet
** File description:
** get_file
*/
#include "my.h"

char **load_caractere(char **tabl, char *str)
{
    int m = 0;
    int i = 0;
    int j = 0;
    for (; str[m] != '\0'; m++){
        if (str[m] == '\n' || str[m + 1] == '\0') {
            tabl[i][j] = str[m];
            tabl[i][j + 1] = '\0';
            i++;
            j = 0;
        } else {
            tabl[i][j] = str[m];
            j++;
        }
    }
    tabl[i] = NULL;
    return tabl;
}

char **load_2d_tabl(char *str)
{
    int nbrow = 0;
    int nbcol = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == '\n')
            nbrow++;
    }
    for (int i = 0; str[i] != '\n'; i++)
        nbcol++;
    char **tabl = malloc(sizeof(char *) * (nbrow + 1));
    for (int k = 0; k < nbrow + 1; k++){
        tabl[k] = malloc(sizeof(char) * (nbcol + 2));
    }
    return tabl;
}

char ** load_file_in_str(char const * filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat a;
    stat(filepath, &a);
    int size = a.st_size;
    char *buffer = malloc((size + 1) * sizeof(char));
    read(fd, buffer, size);
    buffer[size] = '\0';
    char **tabl = load_2d_tabl(buffer);
    tabl = load_caractere(tabl, buffer);
    return tabl;
}

int get_width_hight(t_coordinate *coord, char **buff)
{
    for (int i = 0; buff[i] != NULL; i++) {
        coord->hight = i;
    }
    for (int j = 0; buff[0][j] != '\0'; j++) {
        coord->width = j;
    }
}

void replace_map(char **buff, t_coordinate *coord)
{
    for (int i = 0; buff[i] != NULL; i++) {
            for (int j = 0; buff[i][j] != '\0'; j++) {
                buff[i][j] = coord->buff_save[i][j];
            }
        }
}
