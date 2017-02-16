#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>


void	ft_display_result(char *argv);
char*	parsing(char *argv);
int		check_input(char *buf);
//size_t	check_input(char* buf);
char**	create_tab(char* buf, char*** tab, size_t len_buf);
void	print_tetri(char tab[5][5]);
void	ft_swap(char* a, char* b);
void	move_up_once(char tab[5][5], int x_pos);
void	move_left_once(char tab[5][5], int y_pos);
void	get_abs_tetri(char tab[5][5], int x_pos, int y_pos);


#endif
