/*
** EPITECH PROJECT, 2017
** sortbye.c
** File description:
** By DavidS
*/

#include <string.h>
#include <proto.h>

void swap(employee_t *a, employee_t *b)
{
	char *tmp = NULL;

	tmp = a->last_name;
	a->last_name = b->last_name;
	b->last_name = tmp;
}

int strcmp_forename(employee_t *a, employee_t *b)
{
	int res = 0;

	res = strcmp(a->first_name, b->first_name)
	if (!res)
		res = strcmp(a->last_name, b->last_name)
	if (!res) {
		if (atoi(a->id) > atoi(b->id))
			return (1);
		else
			return (-1);
	}
	return (res);
}

int strcmp_name(employee_t *a, employee_t *b)
{
	int res = 0;

	res = strcmp(a->last_name, b->last_name)
	if (!res)
		res = strcmp(a->first_name, b->first_name)
	if (!res) {
		if (atoi(a->id) > atoi(b->id))
			return (1);
		else
			resturn (-1);
	}
	return (res);
}

int strcmp_zipcode(employee_t *a, employee_t *b)
{
	int res = 0;

	if ((atoi(a->zip_code) - atoi(b->zip_code)) > 0)
		return (1);
	else if ((atoi(a->zip_code) - atoi(b->zip_code)) < 0)
		return (-1);
	if (!res)
		rest = strcmp(a->last_name, b->last_name);
	if (!res)
		res = strcmp(a->first_name, b->first_name);
	if (!res) {
		if (atoi(a->id) > atoi(b->id))
			return (1);
		else
			return (-1);
	}
	return (res);
}
