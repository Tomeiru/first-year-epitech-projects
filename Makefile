##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	absol.c	\
		biggest_number.c	\
		error.c	\
		infinadd.c	\
		is_valid_num.c	\
		longest_string.c	\
		main.c	\
		my_sign.c	\
		same_tenth.c	\
		stenth_dsign.c	\
		stenth_ssign.c

INC_PATH=include

NAME = do-op

OBJ = 	$(SRC:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra

LIBS =	-L lib/my -lmy

$(NAME):	$(OBJ)
		@$(MAKE)	-s	-C	lib/my
		@gcc -o $(NAME) $(OBJ) $(LIBS) $(CFLAGS)

all:	$(NAME)

clean:	
		rm -f $(OBJ)
		@$(MAKE)	-s	-C	lib/my fclean

fclean:	clean
		rm -fr $(NAME)

re:	fclean all