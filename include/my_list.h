/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** mylist
*/

#ifndef MY_LIST_H_
#define MY_LIST_H_

#include <stdlib.h>

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

void my_add_at_end_list(linked_list_t **begin, void *data);
void my_add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)());
void my_rev_list(linked_list_t **list);
void my_sort_list(linked_list_t **begin, int (*cmp)());

#endif /* !MY_LIST_H_ */
