/*
** EPITECH PROJECT, 2017
** tools.c
** File description:
** By DavidS
*/

#include <stdio.h>
#include <stdlib.h>
#include "proto.h"

void free_list_e(employee_t *first)
{
	employee_t *recupe = NULL;

	while (first) {
		recupe = first->next;
		free(first->id);
		free(first->last_name);
		free(first->first_name);
		free(first->position);
		free(first->zip_code);
		free(first);
		first = recupe;
	}
}

void free_list_m(meeting_t *first)
{
	meeting_t *recupe = NULL;

	while (first) {
		recupe = first->next;
		free(first->id);
		free(first->day);
		free(first->zip_code);
		free(first);
		first = recupe;
	}
}

void free_array(char **tab)
{
	int i = 0;

	while (tab && tab[i]) {
		free(tab[i]);
		i++;
	}
	free(tab);
}
