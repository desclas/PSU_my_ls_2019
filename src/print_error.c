/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** print_error
*/

#include "my_ls.h"

void print_error(char *str)
{
    write(2, str, my_strlen(str));
}
