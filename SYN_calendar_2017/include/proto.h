/*
** EPITECH PROJECT, 2017
** proto.h
** File description:
** proto.h
*/

typedef struct employee_s
{
	char *id;
	char *last_name;
	char *first_name;
	char *position;
	char *zip_code;
	int *fired;
	int fired_index;
	struct employee_s *prev;
	struct employee_s *next;
} employee_t;

typedef struct meeting_s
{
	char *id;
	char *day;
	char *zip_code;
	struct meeting_s *prev;
	struct meeting_s *next;
} meeting_t;

#ifndef PROTO_H_
#define PROTO_H_

void read_file(employee_t **employees, meeting_t **meetings);
char **str_to_word_tab(char const *, char);
int strlength(char **);
void free_list_e(employee_t *);
void free_list_m(meeting_t *first);
int display_h(int, char **);
void manage_cmd(char **line, employee_t **employees,
		meeting_t **meetings);
void new_employee_func(char **line, employee_t **employees,
		meeting_t **meetings);
void new_meeting_func(char **line, employee_t **employees,
		meeting_t **meetings);
int arraylength (char **tab);
void fire_func(char **array_line, employee_t **employees,
		meeting_t **meetings);
int *addfired(int id, int return_this);
int contains(int *array, int id);
void free_array(char **tab);
int calendar(employee_t *list_employees, meeting_t *list_meetings);

typedef struct {
	char name[30];
	void (*ptr) (char **array_line, employee_t **employees,
			meeting_t **meetings);
} cmd_ptr_t;

static const cmd_ptr_t COMMANDS[3] = {
	{"new_employee", new_employee_func},
	{"new_meeting", new_meeting_func},
	{"fire", fire_func}
};
#endif
