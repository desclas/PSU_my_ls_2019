/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls_long_print
*/

#include "my_ls.h"

static void add_long_format_info(struct stat stat, data_long_t *new)
{
    new->print = my_append_char(new->print, (stat.st_mode & S_IRUSR) ? 'r':'-');
    new->print = my_append_char(new->print, (stat.st_mode & S_IWUSR)?'w' : '-');
    new->print = my_append_char(new->print, (stat.st_mode & S_IXUSR)?'x' : '-');
    new->print = my_append_char(new->print, (stat.st_mode & S_IRGRP)?'r' : '-');
    new->print = my_append_char(new->print, (stat.st_mode & S_IWGRP)?'w' : '-');
    new->print = my_append_char(new->print, (stat.st_mode & S_IXGRP)?'x' : '-');
    new->print = my_append_char(new->print, (stat.st_mode & S_IROTH)?'r' : '-');
    new->print = my_append_char(new->print, (stat.st_mode & S_IWOTH)?'w' : '-');
    new->print = my_append_char(new->print, (stat.st_mode & S_IXOTH)?'x' : '-');
    new->print = my_append_char(new->print, ' ');
    new->print = my_append_str(new->print, my_ultoa(stat.st_nlink));
    new->print = my_append_char(new->print, ' ');
    new->print = my_append_str(new->print,
        my_strdup(getpwuid(stat.st_uid)->pw_name));
    new->print = my_append_char(new->print, ' ');
    new->print = my_append_str(new->print,
        my_strdup(getgrgid(stat.st_gid)->gr_name));
    new->print = my_append_char(new->print, ' ');
    new->print = my_append_str(new->print, my_ltoa(stat.st_size));
    new->print = my_append_char(new->print, ' ');
}

static void add_long_format_date(__time_t time, data_long_t *new)
{
    char *date = ctime(&time);
    char *tmp = malloc(sizeof(char) * 10);
    size_t count;
    my_memset(tmp, 0, 10);
    for (; *date != ' '; date++);
    for (count = 0, date = date + 1; date[count] != ' '; count++);
    new->print = my_append_str(new->print, my_strdup(my_strncat(tmp, date, count)));
    new->print = my_append_char(new->print, ' ');
    my_memset(tmp, 0, 10);
    for (; *date != ' '; date++);
    for (; *date == ' '; date++);
    for (count = 0; date[count] != ' '; count++);
    new->print =my_append_str(new->print,my_strdup(my_strncat(tmp,date,count)));
    new->print = my_append_char(new->print, ' ');
    my_memset(tmp, 0, 10);
    for (; *date != ' '; date++);
    for (; *date == ' '; date++);
    date++;
    if (date[my_strlen(date) - 2] != '9')
        my_strncat(tmp, &date[my_strlen(date) - 5], 4);
    else {
        for (count = 0; date[count] != ':'; count++);
        for (count = count + 1; date[count] != ':'; count++);
        my_strncat(tmp, date, count);
    }
    new->print = my_append_str(new->print, my_strdup(tmp));
    free(tmp);
}

static data_long_t *add_long_format(data_file_t *data)
{
    data_long_t *new = malloc(sizeof(*new));
    __mode_t itab[] = {S_IFDIR, S_IFLNK, S_IFSOCK, S_IFCHR, S_IFIFO, S_IFBLK};
    char ctab[] = {'d', 'l', 's', 'c', 'f', 'b'};

    new->name = data->name;
    new->print = malloc(sizeof(char));
    new->print[0] = '\0';
    for (size_t i = 0;;i++)
        if (i == 6) {
            new->print = my_append_char(new->print, '-');
            break;
        } else if ((data->stat.st_mode & S_IFMT) == itab[i]) {
            new->print = my_append_char(new->print, ctab[i]);
            break;
        }
    new->time = data->stat.st_mtime;
    add_long_format_info(data->stat, new);
    add_long_format_date(data->stat.st_mtime, new);
    return (new);
}

static void free_long(linked_list_t *data)
{
    for (linked_list_t *i = data->next; data != NULL; data = i) {
        i = (data != NULL) ? data->next : NULL;
        if (data->data != NULL) {
            free(((data_long_t *)data->data)->print);
            free(data->data);
        }
        free(data);
    }
}

void my_ls_long_print(linked_list_t *tmp)
{
    linked_list_t *long_format = malloc(sizeof(*long_format));

    long_format->data = NULL;
    long_format->next = NULL;
    for (linked_list_t *i = tmp; i != NULL; i = i->next)
        if (i->data != NULL && ((data_file_t *)i->data)->name[0] != '.')
            my_add_at_end_list(&long_format, add_long_format((i->data)));
    ls_print_long_format(tmp, long_format);
    free_long(long_format);
}
