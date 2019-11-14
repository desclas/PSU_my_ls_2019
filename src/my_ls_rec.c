/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls_rec
*/

#include "my_ls.h"

static char *temporary_path(char *path, char *name)
{
    char *tpath;

    tpath = my_strdup(path);
    if (tpath[my_strlen(tpath) - 1] != '/')
        tpath = my_append_char(tpath, '/');
    tpath = my_append_str(tpath, my_strdup(name));
    return (tpath);
}

static void my_ls_rec_loop(char *path, struct dirent *file,
    struct stat st, ls_t *tmp)
{
    char *tpath = NULL;
    char link = 0;

    tpath = temporary_path(path, file->d_name);
    stat(tpath, &st);
    tmp->tmp = tpath;
    if (S_ISDIR(st.st_mode) && readlink(tpath, &link, 1) <= 0)
        my_ls_rec(tmp);
    free(tpath);
}

void my_ls_rec(ls_t *tmp)
{
    struct dirent *file;
    struct stat st = {0};
    DIR *fd;
    char *path = NULL;

    my_putstr(tmp->tmp);
    my_putstr(":\n");
    my_ls(tmp);
    my_putchar('\n');
    fd = opendir(tmp->tmp);
    if (fd == NULL)
        return;
    path = my_strdup(tmp->tmp);
    for (file = readdir(fd); file != NULL; file = readdir(fd))
        if (file->d_name[0] != '.')
            my_ls_rec_loop(path, file, st, tmp);
    closedir(fd);
    free(path);
}
