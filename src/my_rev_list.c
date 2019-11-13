/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** my_rev_list
*/

#include "my_list.h"

void my_rev_list(linked_list_t **list)
{
    linked_list_t *res = NULL;
    linked_list_t *first = *list;
    linked_list_t *tmp = NULL;

    if (first->next == NULL || *list == NULL)
        return;
    for (res = first; res->next != NULL; res = res->next);
    for (linked_list_t *i = first; first->next != NULL; i = first) {
        for (; i->next->next != NULL; i = i->next);
        for (tmp = res; tmp->next != NULL; tmp = tmp->next);
        i->next = NULL;
        tmp->next = i;
    }
    *list = res;
}
