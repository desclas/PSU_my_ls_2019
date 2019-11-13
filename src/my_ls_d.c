/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls_d
*/

#include "my_ls.h"

void my_ls_d(ls_t *tmp)
{
    DIR *fd;

    fd = opendir(tmp->tmp);
    if (fd == NULL) {
        print_error("errno");
    }
    closedir(fd);
    my_putstr(tmp->tmp);
    my_putchar('\n');
}
