/*
** EPITECH PROJECT, 2017
** requirement.c
** File description:
** By DavidS
*/

#include <stdio.h>
#include <stdlib.h>
#include "requirement.h"

int my_revlist_synthesis(list_t **begin)
{
	list_t *next = NULL;
	list_t *rest = NULL;
	list_t *prev = *begin;

	if (*begin == NULL)
		return (84);
	while (prev) {
		next = prev->next;
		prev->next = rest;
		rest = prev;
		prev = next;
	}
	*begin = rest;
	return (0);
}

list_t *my_findnodeeqinlist_synthesis(list_t *begin, void *data_ref,
					int(*cmp)(void *, void *))
{
	if (begin != NULL) {
		while (begin && cmp(begin->data, data_ref))
			begin = begin->next;
			return (begin);
		}
	else
		return (NULL);
}
