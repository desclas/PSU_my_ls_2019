##
## EPITECH PROJECT, 2019
## CPool_finalstumper_2019
## File description:
## Makefile
##

DEBUG =
ifeq ($(DEBUG),yes)
CFLAGS	=	-Iinclude -W -Wall -Wextra -Werror -g3
else
CFLAGS	=	-Iinclude -W -Wall -Wextra -Werror
endif

NAME	=	my_ls

SRC	=	main.c					\
		my_add_at_end_list.c	\
		my_rev_list.c			\
		my_sort_list.c			\
		my_base_ls.c			\
		my_cmp_data.c			\
		my_ls_long_print.c		\
		my_make_data.c			\
		ls_print_long_format.c	\
		print_error.c			\
		my_ls_d.c				\
		my_ls_rec.c

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-L../lib/my -lmy

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)
	cp $@ ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re rush3
