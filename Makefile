##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	main.c	\
		my_atoi.c	\
		eval_expr.c	\
		error.c	\
		infin/info.c	\
		infin/same_tenth.c	\
		infin/use_longest.c	\
		infin/add/infin_add.c	\
		infin/add/calc_add.c	\
		infin/sub/infin_sub.c	\
		infin/mult/infin_mult.c	\
		infin/mult/calc_mult.c	\
		infin/div/infin_div.c	\
		infin/div/calc_div.c	\
		infin/mod/infin_mod.c	\
		infin/mod/calc_mod.c

INC_PATH =	include

NAME =	calc

OBJ = 	$(SRC:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra -g

LIBS =	-L lib/my -lmy

$(NAME):	$(OBJ)
		@$(MAKE)	-s	-C	lib/my
		@gcc -g -o $(NAME) $(OBJ) $(LIBS) $(CFLAGS)

all:	$(NAME)

clean:	
		rm -f $(OBJ)
		@$(MAKE)	-s	-C	lib/my fclean

fclean:	clean
		rm -fr $(NAME)

re:	fclean all