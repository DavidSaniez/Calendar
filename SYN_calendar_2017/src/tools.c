/*
** EPITECH PROJECT, 2017
** tools.c
** File description:
** By DavidS
*/

#include <stdlib.h>
#include <stdio.h>
#include "proto.h"

int arraylength (char **tab)
{
	int i = 0;

	while (tab[i])
		i++;
	return (i);
}

int *addfired(int id, int return_this)
{
	static int index = -1;
	static int *fired = NULL;

	if (fired == NULL) {
		fired = malloc(sizeof(int) * 2);
		if (!fired)
			exit(84);
		fired[++index] = id;
		fired[++index] = -1;
		return (return_this == 1 ? fired : NULL);
	}
	fired = realloc(fired, (sizeof(int) * (index + 2)));
	if (fired == NULL)
		exit(84);
	fired[index] = id;
	fired[++index] = -1;
	return (return_this == 1 ? fired : NULL);
}

int contains(int *array, int id)
{
	for (int i = 0; array[i] != -1; i++) {
		if (array[i] == id)
			return (1);
	}
	return (0);
}

void fire_func(char **array_line, employee_t **employees,
		meeting_t **meetings)
{
	int id = 0;
	(void)employees;
	(void)meetings;

	for (int i = 0; array_line[i]; i++) {
		id = atoi(array_line[i]);
		if (id < 0)
			return;
		addfired(id, 0);
	}
}
