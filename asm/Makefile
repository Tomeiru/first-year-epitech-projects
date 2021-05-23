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
		src/create_file/setup/filename_to_filename_cor.c	\
		src/create_file/setup/error/error_check_file.c	\
		src/create_file/setup/error/check_after_quotes.c	\
		src/create_file/setup/error/name/check_error_code.c	\
		src/create_file/setup/error/name/check_name_presence.c	\
		src/create_file/setup/error/name/check_name.c	\
		src/create_file/setup/error/name/check_syntax_name.c	\
		src/create_file/setup/error/comment/check_error_code.c	\
		src/create_file/setup/error/comment/check_comment_presence.c	\
		src/create_file/setup/error/comment/check_comment.c	\
		src/create_file/setup/error/comment/check_syntax_comment.c	\
		src/create_file/setup/error/prog_content/check_command_prog.c	\
		src/create_file/setup/error/prog_content/check_prog.c	\
		src/create_file/setup/error/prog_content/check_args/check_args_line.c	\
		src/create_file/setup/error/prog_content/check_args/check_args_prog.c	\
		src/create_file/setup/error/prog_content/check_args/check_error_code.c	\
		src/create_file/setup/error/prog_content/check_args/check_args_func/check_args_add_sub.c	\
		src/create_file/setup/error/prog_content/check_args/check_args_func/check_args_aff.c	\
		src/create_file/setup/error/prog_content/check_args/check_args_func/check_args_and_or_xor.c	\
		src/create_file/setup/error/prog_content/check_args/check_args_func/check_args_ld_lld.c	\
		src/create_file/setup/error/prog_content/check_args/check_args_func/check_args_ldi_lldi.c	\
		src/create_file/setup/error/prog_content/check_args/check_args_func/check_args_live_zjmp_fork_lfork.c	\
		src/create_file/setup/error/prog_content/check_args/check_args_func/check_args_st.c	\
		src/create_file/setup/error/prog_content/check_args/check_args_func/check_args_sti.c	\
		src/create_file/setup/error/prog_content/check_args/check_args_func/utils/check_direct_arg.c	\
		src/create_file/setup/error/prog_content/check_args/check_args_func/utils/check_indirect_arg.c	\
		src/create_file/setup/error/prog_content/check_args/check_args_func/utils/check_label_arg.c	\
		src/create_file/setup/error/prog_content/check_args/check_args_func/utils/check_register_arg.c	\
		src/create_file/setup/error/prog_content/check_args/check_args_func/utils/count_arg.c	\
		src/create_file/header/get_prog_size.c	\
		src/create_file/header/write_header.c	\
		src/create_file/header/write_magic_number.c	\
		src/create_file/header/write_name.c	\
		src/create_file/header/write_prog_size.c	\
		src/create_file/header/write_comment.c	\
		src/create_file/header/size_func/size_five.c	\
		src/create_file/header/size_func/size_ld_lld.c	\
		src/create_file/header/size_func/size_ldi_lldi.c	\
		src/create_file/header/size_func/size_st.c	\
		src/create_file/header/size_func/size_and_or_xor.c	\
		src/create_file/header/size_func/size_three.c	\
		src/create_file/header/size_func/size_seven.c	\
		src/create_file/header/size_func/size_sti.c	\
		src/create_file/body/write_body.c	\
		src/create_file/body/write_command.c	\
		src/create_file/body/get_command_value.c	\
		src/create_file/body/utils/get_arg_str.c	\
		src/create_file/body/utils/get_args_arr.c	\
		src/create_file/body/utils/get_info_label.c	\
		src/create_file/body/utils/get_command_str.c	\
		src/create_file/body/utils/get_coding_byte.c	\
		src/create_file/body/write_func/get_value.c	\
		src/create_file/body/write_func/write_live.c	\
		src/create_file/body/write_func/write_ld.c	\
		src/create_file/body/write_func/write_st.c	\
		src/create_file/body/write_func/write_add.c	\
		src/create_file/body/write_func/write_sub.c	\
		src/create_file/body/write_func/write_and_first.c	\
		src/create_file/body/write_func/write_and_second.c	\
		src/create_file/body/write_func/write_and_third.c	\
		src/create_file/body/write_func/write_or_first.c	\
		src/create_file/body/write_func/write_or_second.c	\
		src/create_file/body/write_func/write_or_third.c	\
		src/create_file/body/write_func/write_xor_first.c	\
		src/create_file/body/write_func/write_xor_second.c	\
		src/create_file/body/write_func/write_xor_third.c	\
		src/create_file/body/write_func/write_zjmp.c	\
		src/create_file/body/write_func/write_ldi.c	\
		src/create_file/body/write_func/write_ldi_six.c	\
		src/create_file/body/write_func/write_sti.c	\
		src/create_file/body/write_func/write_fork.c	\
		src/create_file/body/write_func/write_lld.c	\
		src/create_file/body/write_func/write_lldi.c	\
		src/create_file/body/write_func/write_lldi_six.c	\
		src/create_file/body/write_func/write_lfork.c	\
		src/create_file/body/write_func/write_aff.c	\
		src/utils/my_getnbr.c	\
		src/utils/my_put_nbr.c	\
		src/utils/my_putchar.c	\
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
