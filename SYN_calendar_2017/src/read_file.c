/*
** EPITECH PROJECT, 2017
** read_file.c
** File description:
** By DavidS
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "proto.h"

void read_file(employee_t **employees, meeting_t **meetings)
{
	int end = 0;
	size_t size = 0;
	char *buffer = NULL;
	char **split = NULL;
	employee_t *test = *employees;
	meeting_t *test2 = *meetings;

	while (getline(&buffer, &size, stdin) != -1) {
		if (strncmp(buffer, "END", 3) == 0)
			end = 1;
		split = str_to_word_tab(buffer, ' ');
		if (split != NULL)
			manage_cmd(split, &test, &test2);
		free_array(split);
	}
	free(buffer);
	if (end == 0)
		exit (84);
	*employees = test;
	*meetings = test2;
}
