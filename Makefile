##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## MAKEFILE
##

## ===========================================================
## ===========================[VAR]===========================
## ===========================================================

NAME			=			my_defender

NAME_TEST		=			unit_test

## ==========================[PATHS]==========================

SRC_PATH		=			src/

UTILS_PATH		=			$(SRC_PATH)utils/

WINDOW_PATH		=			$(SRC_PATH)window/

CREATE_PATH		=			$(SRC_PATH)create/

ACTION_PATH		=			$(SRC_PATH)actions/

MOVE_PATH		=			$(SRC_PATH)move/

DISPLAY_PATH	=			$(SRC_PATH)display/

PARSE_PATH		=			$(SRC_PATH)parse/

INIT_PATH		=			$(SRC_PATH)init/

GAME_PATH		=			$(SRC_PATH)game/

MENU_PATH		=			$(SRC_PATH)menu/

PAUSE_PATH		=			$(SRC_PATH)pause/

LINKED_PATH		=			$(SRC_PATH)linked_list/

FREE_PATH		=			$(SRC_PATH)free/

TEST_PATH		=			tests/

## ===========================[SRC]===========================

SRC_UTILS		=			$(UTILS_PATH)my_error_handling.c		\
							$(UTILS_PATH)my_help.c					\
							$(UTILS_PATH)my_poll_event.c			\

SRC_LINKED		=			$(LINKED_PATH)my_linked_entity.c		\
							$(LINKED_PATH)my_linked_tile.c			\

SRC_WINDOW		=			$(WINDOW_PATH)my_window.c				\

SRC_CREATE		=			$(CREATE_PATH)my_create_ennemies.c		\

SRC_ACTIONS		=			$(ACTION_PATH)my_game_actions.c			\
							$(ACTION_PATH)my_tower_actions.c		\

SRC_MOVE		=			$(MOVE_PATH)my_move_entity.c			\
							$(MOVE_PATH)my_move_directions_entity.c	\

SRC_DISPLAY		=			$(DISPLAY_PATH)my_display_map.c			\
							$(DISPLAY_PATH)my_display_tower.c		\
							$(DISPLAY_PATH)my_display_ennemies.c	\
							$(DISPLAY_PATH)my_display_life.c		\
							$(DISPLAY_PATH)my_display_menu.c		\
							$(DISPLAY_PATH)my_display_money.c		\

SRC_PARSE		=			$(PARSE_PATH)my_parse_path.c			\

SRC_INIT		=			$(INIT_PATH)my_init_game.c				\
							$(INIT_PATH)my_init_ennemies.c			\
							$(INIT_PATH)my_init_life.c				\
							$(INIT_PATH)my_init_music.c				\
							$(INIT_PATH)my_init_menu.c				\
							$(INIT_PATH)my_init_pause.c				\
							$(INIT_PATH)my_init_tile.c				\

SRC_GAME		=			$(GAME_PATH)my_game_loop.c				\
							$(GAME_PATH)my_tower_menu.c				\

SRC_MENU		=			$(MENU_PATH)my_menu_loop.c				\

SRC_PAUSE		=			$(PAUSE_PATH)my_pause_menu.c			\

SRC_FREE		=			$(FREE_PATH)my_free_game.c		\
							$(FREE_PATH)my_free_button.c	\

SRC_GLOBAL		=			$(SRC_UTILS)							\
							$(SRC_LINKED)							\
							$(SRC_WINDOW)							\
							$(SRC_PARSE)							\
							$(SRC_CREATE)							\
							$(SRC_DISPLAY)							\
							$(SRC_ACTIONS)							\
							$(SRC_MOVE)								\
							$(SRC_INIT)								\
							$(SRC_GAME)								\
							$(SRC_MENU)								\
							$(SRC_PAUSE)							\
							$(SRC_FREE)								\

SRC				=			$(SRC_GLOBAL)							\
							main.c

TEST_SRC		=			$(TEST_PATH)tests_error_handling.c		\

OBJ				=			$(SRC:.c=.o)

## =========================[OPTIONS]=========================

CFLAGS			=			-Wall -Wextra -g

CPPFLAGS		=			-I include

LDFLAGS			=			-L lib -lmy							\
							-lcsfml-graphics -lcsfml-system 	\
							-lcsfml-audio -lcsfml-window		\
							-lm									\

CRIT			=			$(LDFLAGS) $(CPPFLAGS) -lcriterion --coverage

## ===========================================================
## ==========================[RULES]==========================
## ===========================================================

all:
		make re -C lib/my
		make $(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

re:			fclean	all

clean:
		make clean -C lib/my
		rm -rf $(OBJ)

fclean:		clean
		make fclean -C lib/my
		rm -rf $(NAME)
		rm -rf $(NAME_TEST)
		rm -rf *gcda
		rm -rf *gcno

tests_run:
	make re -C lib/my
	gcc -o $(NAME_TEST) $(SRC_GLOBAL) $(SRC_TEST) $(TEST_SRC) $(CRIT)
	./$(NAME_TEST)

## ===========================[END]===========================

.PHONY:	all	re	clean	fclean	tests_run
