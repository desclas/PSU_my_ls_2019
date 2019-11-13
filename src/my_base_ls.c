/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_base_ls
*/

#include "my_ls.h"

static void my_ls_standard_print(linked_list_t *tmp)
{
    for (; tmp != NULL; tmp = tmp->next)
        if (tmp->data != NULL && ((data_file_t *)tmp->data)->name[0] != '.') {
            my_putstr(((data_file_t *)tmp->data)->name);
            my_putchar('\n');
        }
}

static void my_ls_print(linked_list_t *tmp, ls_t *stc)
{
    if (stc->flags.rev)
        my_rev_list(&tmp);
    if (stc->flags.l)
        my_ls_long_print(tmp);
    else
        my_ls_standard_print(tmp);
}

static void my_ls_free(linked_list_t *tmp)
{
    for (linked_list_t *i = tmp->next; tmp != NULL; tmp = i) {
        i = (tmp != NULL) ? tmp->next : NULL;
        if (tmp->data != NULL) {
            free(((data_file_t *)tmp->data)->name);
            free(tmp->data);
        }
        free(tmp);
    }
}

void my_ls(ls_t *stc)
{
    linked_list_t *tmp;
    struct dirent *file;
    DIR *fd;

    fd = opendir(stc->tmp);
    if (fd == NULL)
        return (print_error("errno"));
    tmp = malloc(sizeof(*tmp));
    tmp->data = NULL;
    tmp->next = NULL;
    for (file = readdir(fd); file != NULL; file = readdir(fd))
        my_add_in_sorted_list(&tmp, my_make_data(stc, my_strdup(file->d_name)),
            stc->cmp);
    my_ls_print(tmp, stc);
    my_ls_free(tmp);
    closedir(fd);
}
