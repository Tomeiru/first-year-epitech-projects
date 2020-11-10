##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	sources/arg_sort.c	\
		sources/bin_printer.c	\
		sources/det_len.c	\
		sources/flag.c	\
		sources/hexa_printer.c	\
		sources/HEXA_printer.c	\
		sources/int_printer.c	\
		sources/my_printf.c	\
		sources/my_putchar.c	\
		sources/my_putstr.c	\
		sources/my_revstr.c	\
		sources/my_strdup.c	\
		sources/my_strlen.c	\
		sources/oct_printer.c	\
		sources/print_hexadecimal.c	\
		sources/print_numbers.c	\
		sources/print_S.c	\
		sources/uns_printer.c	\
		sources/unsint_printer.c

INC_PATH =	includes

NAME = libmy.a

OBJ = 	$(SRC:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra -g

LIBS =	-L -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:	
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all