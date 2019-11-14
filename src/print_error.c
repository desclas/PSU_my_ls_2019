/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_error
*/

#include "my_ls.h"

void print_error(char *str, char *name, char *file)
{
    char *tmp = my_append_str(my_strdup(name + 2), my_strdup(": cannont "));
    int err = errno;

    if (!my_strcmp(str, "errno")) {
        if (err == ENOTDIR)
            tmp = my_append_str(tmp, my_strdup("acess '"));
        else if (err == EACCES)
            tmp = my_append_str(tmp, my_strdup("open directory '"));
        tmp = my_append_str(tmp, my_strdup(file));
        tmp = my_append_char(tmp, '\'');
        perror(tmp);
    } else
        perror(str);
    free(tmp);
}
