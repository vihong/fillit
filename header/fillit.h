#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "libft.h"
# include "stdbool.h"

typedef struct		s_line
{
	char 			tetris[4][5];
	char 			letter;
	int				ind;
	struct s_line	*prev;
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
int		check_place(char** sq, int sq_size, char tetri[4][5], int pos);
void	put_tetri(char** sq, int sq_size, char tetri[4][5], int pos);
void	remove_tetri(char** sq, int sq_size, char tetri[4][5], int pos);
int		ft_sqrt(int nb);
void	print_sq(char** sq, int sq_size);
int		sq_of(int nb);
int		fill_sq(char** sq, int* sq_size, t_line** tetri1, int* nb_tetri);
int		estValide(char** sq, int* sq_size, t_line** tetri1, int* nb_tetri);

#endif
