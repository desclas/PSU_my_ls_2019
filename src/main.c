/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** main
*/

#include "my_ls.h"

static void init_flags(ls_t *tmp)
{
    tmp->file = NULL;
    tmp->tmp = NULL;
    tmp->flags.d = 0;
    tmp->flags.l = 0;
    tmp->flags.rec = 0;
    tmp->flags.rev = 0;
    tmp->flags.t = 0;
    tmp->cmp = &my_cmp_data_file;
}

static int is_flags(char c)
{
    if (c != 'l' && c != 'R' && c != 'r' && c != 'd' && c != 't')
        return (-1);
    return (0);
}

static int fill_flags(ls_t *tmp, char *flags)
{
    if (flags[0] == '-' && flags[1] != 0 && flags[1] == '-')
        return (-1);
    if (flags[0] != '-')
        return (0);
    for (size_t i = 1; flags[i] != 0; i++) {
        if (is_flags(flags[i]) == -1)
            return (-1);
        if (flags[i] == 'l')
            tmp->flags.l = 1;
        else if (flags[i] == 'R')
            tmp->flags.rec = 1;
        if (flags[i] == 't') {
            tmp->flags.t = 1;
            tmp->cmp = &my_cmp_data_file_time;
        } else if (flags[i] == 'd')
            tmp->flags.d = 1;
        if (flags[i] == 'r')
            tmp->flags.rev = 1;
    }
    return (0);
}

static int print_main_error(char *str, char *name)
{
    write(2, name, my_strlen(name));
    write(2, ": ", 2);
    write(2, str, my_strlen(str));
    write(2, " flag unknown\nusage: ", 22);
    write(2, name, my_strlen(name));
    write(2, " [-lRdrt] [FILE]\n", 18);
    return (84);
}

static void my_choice(ls_t *tmp)
{
    if (tmp->flags.d)
        my_ls_d(tmp);
    else if (tmp->flags.rec)
        my_ls_rec(tmp);
    else
        my_ls(tmp);
}

int main(int av, char **ac)
{
    ls_t tmp;

    init_flags(&tmp);
    tmp.file = "./";
    tmp.tmp = "./";
    if (av == 1)
        my_ls(&tmp);
    for (int i = 1; i < av; i++)
        if (fill_flags(&tmp, ac[i]) < 0)
            return (print_main_error(ac[i], ac[0]));
    for (int i = 1, x = 0; i < av; i++)
        if (ac[i][0] != '-') {
            x = 1;
            tmp.file = ac[i];
            tmp.tmp = ac[i];
            my_choice(&tmp);
        } else if (i + 1 >= av && !x)
            my_choice(&tmp);
    return (0);
}
