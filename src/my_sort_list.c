/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** my_sort_list
*/

#include "my_list.h"

void my_sort_list(linked_list_t **begin, int (*cmp)())
{
    void *sv;

    for (linked_list_t *tmp = *begin; tmp->next != NULL;)
        if ((*cmp)(tmp->data, tmp->next->data) > 0) {
            sv = tmp->data;
            tmp->data = tmp->next->data;
            tmp->next->data = sv;
            tmp = *begin;
        } else
            tmp = tmp->next;
}
