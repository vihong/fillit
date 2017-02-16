.PHONY: all clean fclean re

NAME		= fillit
SRC			= ft_display_result.c parsing.c check_input.c create_tab.c grille.c
D_SRC		= src
OBJ			= $(SRC:.c=.o)
HEADER		= header
LIB			= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= -rm -rf


all: libft.a $(NAME)

$(NAME): $(OBJ)
		@$(CC) main.c -I$(HEADER) $(CFLAGS) -L./libft/ -lft $^ -o $(NAME)

%.o: $(D_SRC)/%.c
		@$(CC) -c -I$(HEADER) $(CFLAGS) $^ -o $@

$(LIB):
		cd libft && make all

clean:
		@$(RM) $(OBJ)

fclean: clean
		@$(RM) $(NAME) && cd libft && make fclean

re: fclean all
