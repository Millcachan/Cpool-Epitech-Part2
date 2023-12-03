##
## EPITECH PROJECT, 2023
## B-CPE-101-STG-1-1-myprintf-camille.billard
## File description:
## Makefile
##

SRC	=	my_printf.c 			\
		lib/my/flag_x.c 		\
		lib/my/flag_o.c 		\
		lib/my/flag_c.c 		\
		lib/my/flag_d.c 		\
		lib/my/flag_a.c			\
		lib/my/flag_s.c 		\
		lib/my/flag_u.c 		\
		lib/my/flag_f.c 		\
		lib/my/flag_p.c			\
		lib/my/flag_e.c         \
		lib/my/flag_n.c 		\
		lib/my/flag_b.c			\
		lib/my/flag_g.c 		\
		lib/my/sub_flag.c		\
		lib/my/my_getnbr.c 		\
		lib/my/flag_up_f.c      \
		lib/my/flag_up_x.c 		\
		lib/my/flag_up_g.c 		\
		lib/my/flag_up_e.c      \
		lib/my/my_strcpy.c 		\
		lib/my/my_strdup.c 		\
		lib/my/my_putstr.c		\
		lib/my/my_strncmp.c		\
		lib/my/int_to_str.c 	\
		lib/my/my_putchar.c 	\
		lib/my/my_put_nbr.c 	\
		lib/my/flag_percent.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-g

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)

tests_run:
	make -C ./tests
	./tests/unit_test

tests_run_fclean:
	make fclean -C ./tests

re: fclean all
