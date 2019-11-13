/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** ls_print_long_format
*/

#include "my_ls.h"

static void get_width(char *lf, size_t width[7])
{
    size_t count;

    for(;*lf != ' ';lf++);
    for (size_t i = 0; i < 7; i++) {
        lf++;
        for (count = 0; lf[count] != ' ' && lf[count] != 0; count++);
        if (width[i] < count)
            width[i] = count;
        lf += count;
    }
}

static size_t get_len_until(char *str, char del)
{
    size_t i;

    for (i = 0; str[i] != del && str[i] != 0; i++);
    return (i);
}

static void print_long_format(data_long_t *data, size_t *width)
{
    char *str = data->print;
    my_putnstr(str, 10);
    str += 11;
    for (size_t i = 0, len = 0; i < 7; i++) {
        my_putchar(' ');
        len = get_len_until(str, ' ');
        if (*str <= '9' && *str >= '0') {
            for (size_t x = width[i] - len; x > 0; x--)
                my_putchar(' ');
            my_putnstr(str, len);
        } else {
            my_putnstr(str, len);
            for (size_t x = width[i] - len; x > 0; x--)
                my_putchar(' ');
        }
        str += len + 1;
    }
    my_putchar(' ');
    my_putstr(data->name);
    my_putchar('\n');
}

void ls_print_long_format(linked_list_t *tmp, linked_list_t *lf)
{
    long bl = 0;
    char *str;
    size_t width[7] = {0};
    for (linked_list_t *i = tmp; i != NULL; i = i->next)
        if (i->data != NULL && ((data_file_t *)i->data)->name[0] != '.')
            bl += ((data_file_t *)i->data)->stat.st_blocks;
    my_putstr("total ");
    str = my_ltoa(bl);
    my_putstr(str);
    free(str);
    my_putchar('\n');
    for (linked_list_t *i = lf; i != NULL; i = i->next)
        if (i->data != NULL)
            get_width(((data_long_t *)i->data)->print, width);
    for (linked_list_t *i = lf; i != NULL; i = i->next)
        if (i->data != NULL)
            print_long_format(((data_long_t *)i->data), width);
}
