/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_cmp_data
*/

#include "my_ls.h"

int my_cmp_data_file(data_file_t *s1, data_file_t *s2)
{
    return (my_strcmp(s1->name, s2->name));
}

int my_cmp_data_file_time(data_file_t *s1, data_file_t *s2)
{
    if (s1->stat.st_mtime > s2->stat.st_mtime)
        return (-1);
    else if (s1->stat.st_mtime < s2->stat.st_mtime)
        return (1);
    else
        return (0);
}

int my_cmp_data_long(data_long_t *s1, data_long_t *s2)
{
    return (my_strcmp(s1->name, s2->name));
}

int my_cmp_data_long_time(data_long_t *s1, data_long_t *s2)
{
    if (s1->time > s2->time)
        return (-1);
    else if (s1->time < s2->time)
        return (1);
    else
        return (0);
}
