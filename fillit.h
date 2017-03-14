/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:12:23 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/14 18:48:06 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct		s_line
{
	char			tetris[4][5];
	char			letter;
	int				pos;
	struct s_line	*prev;
	struct s_line	*next;
}					t_line;

char				*parsing(char *argv);
int					count_tetri(char *str);
int					check_input(char *str);
void				make_tab(char *buf, t_line **tetri, int nb_tetri);
void				add_tetri(t_line **tetris, char *lettre, char tab[4][5]);
void				aff_lst(t_line **tetris);
void				print_tab(char tab[4][5]);
void				init_each_tetri(t_line **tetri1);
void				initialiser(char tab[4][5], int x_pos, int y_pos);
void				ft_swap(char *a, char *b);
void				move_up_once(char tab[4][5], int x_pos);
void				move_left_once(char tab[4][5], int y_pos);
char				**create_sq(int sq_size);
int					check_place(char **sq, int sq_size,
					char tetri[4][5], int pos);
void				put_tetri(char **sq, int sq_size,
					char tetri[4][5], int pos);
void				remove_tetri(char **sq, int sq_size,
					char tetri[4][5], int pos);
int					ft_sqrt(int nb);
void				print_sq(char **sq, int sq_size);
int					sq_of(int nb);
int					solver(char **sq, int sq_size, t_line **tetri1, int pos);
void				fill_with_dots(char **sq, int sq_size);
int					get_closest_sq_size(int nb_tetri);
char				**get_smallest_sq(char **sq, int *sq_size, t_line **tetri1);

#endif
