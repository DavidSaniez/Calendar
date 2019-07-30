/*
** EPITECH PROJECT, 2017
** tools.c
** File description:
** By DavidS
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "proto.h"

int display_h(int ac, char **av)
{
	if (ac > 1 && strcmp(av[1], "-h") == 0 && ac == 2) {
		printf("USAGE");
		printf("\twrite instruction to be standard output \
until the END instruction\n");
		exit (0);
	}
	if (ac > 3)
		exit (84);
	return (0);
}

int display_meeting(meeting_t *list_meetings)
{
	(void)list_meetings;
	return (0);
}
// printf("\n%s ", list_meetings->id);
// printf("%s", list_meetings->day);
// printf(" %s\n", list_meetings->zip_code);
// return (0);

int display_emp(employee_t *list_employees)
{
	printf("%s\n", "******************************" );
	printf("%s ", list_employees->first_name);
	printf("%s\n", list_employees->last_name);
	printf("position: %s\n", list_employees->position);
	printf("city: %s\n", list_employees->zip_code);
	return (0);
}

int calendar(employee_t *list_employees, meeting_t *list_meetings)
{
	employee_t *save = list_employees;
	meeting_t *save2 = list_meetings;
	int *fired = addfired(-1, 1);

	while (list_employees != NULL) {
		if (contains(fired, atoi(list_employees->id)) == 0) {
			display_emp(list_employees);
		}
		list_employees = list_employees->next;
	}
	free_list_e(save);
	while (list_meetings != NULL) {
		display_meeting(list_meetings);
		list_meetings = list_meetings->next;
	}
	free_list_m(save2);
	free(fired);
	return (0);
}

int main(int ac, char **av)
{
	employee_t *list_employees = NULL;
	meeting_t *list_meetings = NULL;

	display_h(ac, av);
	read_file(&list_employees, &list_meetings);
	calendar(list_employees, list_meetings);
	return (0);
}
