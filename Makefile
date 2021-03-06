.PHONY: all clean fclean re

NAME		= 	fillit
SRC			= 	parsing.c \
				count_tetri.c \
				check_input.c \
				make_tab.c \
				add_tetri.c\
				display.c \
				initialiser.c \
				create_sq.c \
				ft_sqrt.c \
				put_or_not.c \
				sq_of.c \
				solver.c \
				fill_with_dots.c \
				get_closest_sq_size.c \
				get_smallest_sq.c \

D_SRC		= 	src
OBJ			= 	$(SRC:.c=.o)
HEADER		= 	header
LIB			= 	libft.a

CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror
RM			= 	-rm -rf


all: $(NAME)
	
$(NAME): $(OBJ)
		make -C ./libft
		@$(CC) main.c $(CFLAGS) -I. -L./libft/ -lft $^ -o $(NAME)

%.o: %.c
		@$(CC) -c $(CFLAGS) -I. $^ -o $@

clean:
		@$(RM) $(OBJ) && cd libft && make clean

fclean: clean
		@$(RM) $(NAME) && cd libft && make fclean

re: fclean all
