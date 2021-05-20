##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	src/setup/asm_corewar.c	\
		src/setup/fill_info_struct.c	\
		src/setup/op.c	\
		src/create_file/setup/asm_file.c	\
		src/create_file/setup/create_cor_file.c	\
		src/create_file/setup/error_check_file.c	\
		src/create_file/setup/filename_to_filename_cor.c	\
		src/create_file/header/write_header.c	\
		src/create_file/header/write_magic_number.c	\
		src/create_file/header/write_name.c	\
		src/create_file/header/write_prog_size.c	\
		src/create_file/header/write_comment.c	\
		src/utils/my_strcmp.c	\
		src/utils/my_strdup.c	\
		src/utils/my_strlen.c	\
		src/utils/str_to_array.c	\

MAIN =	src/setup/main.c

INC_PATH =	include

NAME =	asm

OBJ = 	$(SRC:.c=.o)

OBJMAIN = 	$(MAIN:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra

$(NAME):	$(OBJ)	$(OBJMAIN)
		@gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(CFLAGS)

all:	$(NAME)

debug:	CFLAGS += -g
debug:	fclean all
		@gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(CFLAGS)

clean:	
		rm -f $(OBJ) $(OBJMAIN)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all
