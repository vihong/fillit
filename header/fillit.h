#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_line
{
	char 			tetris[4][5];
	char 			letter;
	struct s_line 	*next;
}					t_line;


	/* ETAPE 1 */ 

char*	parsing(char *argv);

int		count_tetri(char *str);
int		check_input(char *str);

void	make_tab(char* buf, t_line** tetri, int nb_tetri);
void 	add_tetri(t_line **tetris, char *lettre, char tab[4][5]);
void 	aff_lst(t_line **tetris);
void	print_tab(char tab[4][5]);

void	initialiser(char tab[4][5], int x_pos, int y_pos);
void	ft_swap(char* a, char* b);
void	move_up_once(char tab[4][5], int x_pos);
void	move_left_once(char tab[4][5], int y_pos);

char	**create_square(int sq_size);



#endif
