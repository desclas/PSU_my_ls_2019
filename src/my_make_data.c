/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_make_data
*/

#include "my_ls.h"

data_file_t *my_make_data(ls_t *stc, char *name)
{
    data_file_t *res = malloc(sizeof(*res));
    size_t len = my_strlen(name) + my_strlen(stc->tmp);
    char *path = malloc(sizeof(char) * (len + 2));

    for (size_t i = 0; i < len + 2; i++)
        path[i] = 0;
    res->name = name;
    my_strcat(path, stc->tmp);
    if (stc->tmp[my_strlen(stc->tmp) - 1] != '/')
        my_strcat(path, "/");
    my_strcat(path, name);
    stat(path, &res->stat);
    free(path);
    return (res);
}
