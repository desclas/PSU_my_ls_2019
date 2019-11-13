/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "my_list.h"

typedef struct data_file_s {
    char *name;
    struct stat stat;
} data_file_t;

typedef struct data_long_s {
    char *name;
    char *print;
    __time_t time;
} data_long_t;

typedef struct ls_s
{
    char *file;
    char *tmp;
    struct {
        char rec;
        char rev;
        char d;
        char t;
        char l;
    } flags;
    int (*cmp)();
} ls_t;

void my_ls(ls_t *);
int my_cmp_data_file(data_file_t *, data_file_t *);
int my_cmp_data_long(data_long_t *, data_long_t *);
int my_cmp_data_file_time(data_file_t *, data_file_t *);
int my_cmp_data_long_time(data_long_t *, data_long_t *);
data_file_t *my_make_data(ls_t *, char *);
void my_ls_long_print(linked_list_t *);
void ls_print_long_format(linked_list_t *, linked_list_t *);
void print_error(char *);
void my_ls_d(ls_t *);
void my_ls_rec(ls_t *);

#endif /* !MY_LS_H_ */
