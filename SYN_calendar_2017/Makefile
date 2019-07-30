##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## By DavidS
##

CC	=	gcc

NAME	=	calendar

SRCS	=	src/employees.c		\
		src/main.c 		\
		src/read_file.c 	\
		src/str_to_word_tab.c	\
		src/free_lknd_list.c	\
		src/tools.c

OBJ	=	$(SRCS:.c=.o)

RM	=	rm -f

CFLAGS	+=	-g -W -Wall -Wextra  -I./include

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	re fclean clean all
