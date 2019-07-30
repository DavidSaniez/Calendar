/*
** EPITECH PROJECT, 2017
** employees.c
** File description:
** By DavidS
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "proto.h"

meeting_t *list_append_meeting(meeting_t **list, meeting_t *meeting)
{
	meeting_t *tmp = *list;

	if (meeting == NULL) {
		return (NULL);
	}
	if (*list == NULL) {
		meeting->prev = NULL;
		meeting->next = NULL;
		return (meeting);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = meeting;
	meeting->prev = tmp;
	meeting->next = NULL;
	return (meeting);
}

employee_t *list_append_employee(employee_t **list, employee_t *employee)
{
	employee_t *tmp = *list;

	if (employee == NULL)
		return (NULL);
	if (*list == NULL) {
		employee->prev = NULL;
		employee->next = NULL;
		return (employee);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = employee;
	employee->prev = tmp;
	employee->next = NULL;
	return (employee);
}

void new_employee_func(char **array_line, employee_t **employees,
			meeting_t **meetings)
{
	employee_t *employee = malloc(sizeof(employee_t));
	(void)meetings;

	if (employees == NULL)
		return;
	if (arraylength(array_line) < 5) {
		free(employee);
		return;
	}
	if (!employee)
		return;
	employee->last_name = strdup(array_line[0]);
	employee->first_name = strdup(array_line[1]);
	employee->position = strdup(array_line[2]);
	employee->zip_code = strdup(array_line[3]);
	employee->id = strdup(array_line[4]);
	if (atoi(employee->id) < 0)
		return;
	if (*employees == NULL) {
		(*employees) = list_append_employee(employees, employee);
	} else
		list_append_employee(employees, employee);
}

void new_meeting_func(char **array_line, employee_t **employees,
		meeting_t **meetings)
{
	meeting_t *meeting = malloc(sizeof(meeting_t));
	(void)employees;

	if (meeting == NULL)
		return;
	if (arraylength(array_line) < 3) {
		free(meeting);
		return;
	}
	if (!meeting)
		return;
	meeting->id = strdup(array_line[0]);
	meeting->day = strdup(array_line[1]);
	meeting->zip_code = strdup(array_line[2]);
	if (*meetings == NULL) {
		(*meetings) = list_append_meeting(meetings, meeting);
	} else {
		list_append_meeting(meetings, meeting);
	}
}

void manage_cmd(char **line, employee_t **employees, meeting_t **meetings)
{
	if (line == NULL)
		return;
	for (int i = 0; i < 3; i++) {
		if (strcmp(COMMANDS[i].name, line[0]) == 0)
			COMMANDS[i].ptr(&line[1], employees, meetings);
	}
}
