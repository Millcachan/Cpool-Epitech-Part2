##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile rush3
##

SRC	=	rush3.c

OBJ	=	$(SRC:.c=.o)

NAME	=	rush3

all:	$(NAME)

$NAME:	$(OBJ)
	make -C
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
