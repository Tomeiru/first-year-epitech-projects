##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	sources/cast_struct.c	\
		sources/event.c		\
		sources/events_options_menu.c	\
		sources/ini_struct.c	\
		sources/main_menu.c		\
		sources/my_defender.c	\
		sources/options_menu.c	\
		sources/scene_manager.c	\
		sources/game_scene.c	\
		sources/event_game.c

MAIN =	main.c

INC_PATH =	include

NAME =	my_defender

OBJ = 	$(SRC:.c=.o)

OBJMAIN = 	$(MAIN:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra -g

LIBS =	-lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio

$(NAME):	$(OBJ)	$(OBJMAIN)
		@gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(LIBS) $(CFLAGS)

all:	$(NAME)

clean:	
		rm -f $(OBJ) $(OBJMAIN)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all