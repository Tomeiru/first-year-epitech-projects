##
## EPITECH PROJECT, 2020
## my_rpg
## File description:
## Makefile
##

MAIN_SRC		=	src/main.c													\
					src/my_rpg.c												\
					src/events.c												\
					src/infos.c													\
					src/graphics/textures.c										\
					src/graphics/subwindow.c									\
					src/graphics/default_subwindow_fcts.c						\
					src/graphics/pause.c										\
					src/sounds/sounds.c

ELEMENTS_SRC	=	src/elements/element.c										\
					src/elements/default_element_fcts.c							\
					src/elements/image.c										\
					src/elements/entities/particle.c							\
					src/elements/entities/text.c								\
					src/elements/entities/text_update_fcts.c					\
					src/elements/entities/buttons/button.c						\
					src/elements/entities/buttons/button_default_fcts.c			\
					src/elements/entities/buttons/button_types.c				\
					src/elements/entities/buttons/button_actions.c				\
					src/elements/entities/buttons/button_load_actions.c

SCENE_SRC		=	src/scene/scene.c											\
					src/scene/scene_elements.c									\
					src/scene/load_scene.c										\
					src/scene/menu_scene.c										\
					src/scene/howtoplay/howtoplay_scene.c						\
					src/scene/howtoplay/button_htp_actions.c					\
					src/scene/settings/settings_scene.c							\
					src/scene/settings/settings_subwindows.c					\
					src/scene/settings/button_settings_actions.c				\
					src/scene/settings/button_settings_res_actions.c			\
					src/scene/world/world_scene.c								\
					src/scene/world/world.c										\
					src/scene/world/inventory.c

UTILS_SRC		=	src/utils/utils.c											\
					src/utils/origins.c											\
					src/utils/elements_interact.c

LIB_DIR		=	./mylib
INC_DIR		=	./include

SFML_LIB	=	-lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio

CFLAGS		+=	-W -Wall -I$(INC_DIR)

OBJ			=	$(MAIN_SRC:.c=.o) $(ELEMENTS_SRC:.c=.o) $(SCENE_SRC:.c=.o) $(UTILS_SRC:.c=.o)

NAME		=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C $(LIB_DIR)
	gcc -o $(NAME) $(OBJ) -I$(INC_DIR) -L$(LIB_DIR) $(SFML_LIB) -lm -lmy

debug:	CFLAGS += -g
debug: 	$(OBJ)
	make -C $(LIB_DIR) debug
	gcc -g -o $(NAME) $(OBJ) -I$(INC_DIR) -L$(LIB_DIR) $(SFML_LIB) -lm -lmy

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all