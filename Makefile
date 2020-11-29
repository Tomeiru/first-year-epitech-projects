##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	Essential_functions/capr_flag.c	\
		Essential_functions/d_flag.c	\
		Essential_functions/l_flag.c	\
		Essential_functions/ls_sorter.c	\
		Essential_functions/my_ls.c	\
		Essential_functions/my_strcmp.c	\
		Printers/array_creators.c	\
		Printers/array_creators_second.c	\
		Printers/array_creators_third.c	\
		Printers/caps_r_gestion.c	\
		Printers/caps_rr_gestion.c	\
		Printers/caps_rrl_gestion.c	\
		Printers/caps_rl_gestion.c	\
		Printers/dash_l.c	\
		Printers/file_name_to_array.c	\
		Printers/no_arguments.c	\
		Printers/single_l.c	\
		Printers/string_creators_second.c	\
		Printers/string_creators.c

MAIN =	Essential_functions/main.c

INC_PATH =	include

NAME =	my_ls

OBJ = 	$(SRC:.c=.o)

OBJMAIN = 	$(MAIN:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra -g

LIBS =	-L. -lmy

$(NAME):	$(OBJ)	$(OBJMAIN)
		@gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(LIBS) $(CFLAGS)

all:	$(NAME)

clean:	
		rm -f $(OBJ) $(OBJMAIN) $(OBJTEST)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all