/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** my_add_in_sorted_list
*/

#include "my_list.h"

void my_add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)())
{
    linked_list_t *new = malloc(sizeof(*new));
    linked_list_t *tnew;
    linked_list_t *tmp;

    new->data = data;
    new->next = NULL;
    if ((*begin)->data == NULL) {
        free(new);
        (*begin)->data = data;
        return;
    }
    if ((*cmp)((*begin)->data, new->data) > 0) {
        new->next = *begin;
        *begin = new;
        return;
    }
    for (tmp = *begin, tnew = tmp->next; tnew != NULL; tmp = tnew,
        tnew = tnew->next)
        if ((*cmp)(tnew->data, new->data) > 0) {
            new->next = tmp->next;
            tmp->next = new;
            return;
        }
    tmp->next = new;
}

void my_add_at_end_list(linked_list_t **begin, void *data)
{
    linked_list_t *new = malloc(sizeof(*new));
    linked_list_t *tnew = *begin;

    new->data = data;
    new->next = NULL;
    if (tnew->data == NULL) {
        free(new);
        tnew->data = data;
        return;
    }
    for (; tnew->next != NULL; tnew = tnew->next);
    tnew->next = new;
}
