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
		sources/hexamin_printer.c	\
		sources/hexamaj_printer.c	\
		sources/int_printer.c	\
		sources/my_printf.c	\
		sources/my_getnbr.c	\
		sources/lib_function.c	\
		sources/oct_printer.c	\
		sources/print_hexadecimal.c	\
		sources/print_numbers.c	\
		sources/print_string.c	\
		sources/uns_printer.c	\
		sources/unsint_printer.c	\
		sources/type_sort.c	\
		sources/print_width.c	\
		sources/width_modifier.c	\
		sources/type_sort.c	\

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