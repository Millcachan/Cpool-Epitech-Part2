##
## EPITECH PROJECT, 2023
## B-CPE-101-STG-1-1-myprintf-camille.billard
## File description:
## Makefile
##

src = 	test_myprintf.c 			\
		test_myprintf_c.c 			\
		test_myprintf_d.c 			\
		test_myprintf_f.c 			\
		test_myprintf_e.c 			\
		test_myprintf_g.c 			\
		test_myprintf_x.c 			\
		test_myprintf_s.c 			\
		test_myprintf_o.c 			\
		test_myprintf_multiflag.c 	\

obj = $(src:.c=.o)

lib = -L../ -lmy

CFLAGS = --coverage -lcriterion

name = unit_test

all : $(name)

$(name) : $(obj)
	make -C ../
	gcc -o $(name) $(src) $(lib) $(CFLAGS)

clean :
	make clean -C ../
	rm -f $(obj)
	rm -f *.o
	rm *.gcno

fclean : clean
	make fclean -C ../
	rm -f $(name)
	rm *.gcda
	rm *.gcno
	rm ../lib/my/*.gcda

re : fclean all
	make re -C ../
