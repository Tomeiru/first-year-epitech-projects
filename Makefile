##
## EPITECH PROJECT, 2021
## need4stek
## File description:
## makefile
##

SRC			=	src/main.c

INC_DIR		=	./include

CFLAGS		+=	-W -Wall -I$(INC_DIR)

OBJ			=	$(SRC:.c=.o)

NAME		=	ai

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -lm

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all