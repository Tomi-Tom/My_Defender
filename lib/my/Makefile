##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## first makefile
##

## ===========================[VAR]===========================

NAME 	= 	libmy.a

CFLAG 	= 	-Wall -Wextra -g

SRC		=	disp_stdarg.c				\
			do_op.c						\
			is_num.c					\
			my_compute_power_rec.c		\
			my_compute_square_root.c	\
			my_find_prime_sup.c			\
			my_getnbr.c					\
			my_is_greater.c				\
			my_is_prime.c				\
			my_isneg.c					\
			my_itoa.c					\
			my_linked_list.c			\
			my_printf.c					\
			my_put_nbr_l.c				\
			my_put_nbr_ll.c				\
			my_put_nbr_u.c				\
			my_put_nbr.c				\
			my_putchar.c				\
			my_puterror.c				\
			my_putnbr_base.c			\
			my_putstr.c					\
			my_remove_sub.c				\
			my_revstr.c					\
			my_sort_int_array.c			\
			my_split.c					\
			my_str_isalpha.c			\
			my_str_islower.c			\
			my_str_isnum.c				\
			my_str_isprintable.c		\
			my_str_isupper.c			\
			my_strcapitalize.c			\
			my_strcat.c					\
			my_strcmp.c					\
			my_strcpy.c					\
			my_strdup.c					\
			my_strlen.c					\
			my_strlowcase.c				\
			my_strncat.c				\
			my_strncmp.c				\
			my_strncpy.c				\
			my_strstr.c					\
			my_strupcase.c				\
			my_swap.c					\
			my_read_file.c				\
			my_exit.c					\
			my_puttab.c					\
			my_free_array.c				\
			my_arrcat.c					\

OBJ 	= 	$(SRC:.c=.o)

## ==========================[RULES]==========================

all:		$(NAME)
		mkdir -p ../../include
		cp -rf my.h ../../include
		cp -rf $(NAME) ..

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

re:			fclean	all

clean:
		rm -f *.o

fclean:		clean
		rm -f libmy.a
		rm -f ../libmy.a

## ===========================[END]===========================

.PHONY:	all	re	clean	fclean
