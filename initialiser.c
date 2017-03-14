/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:07:15 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/09 02:36:12 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_swap(char *a, char *b)
{
	char c;

	c = *a;
	*a = *b;
	*b = c;
}

void	move_up_once(char tab[4][5], int x_pos)
{
	int i;
	int k;

	i = x_pos;
	k = -1;
	while (tab[i][k] && k++ < 4)
		ft_swap(&tab[i][k], &tab[i - 1][k]);
}

void	move_left_once(char tab[4][5], int y_pos)
{
	int j;
	int k;

	j = y_pos;
	k = 0;
	while (tab[k][j] && k < 4)
	{
		ft_swap(&tab[k][j], &tab[k][j - 1]);
		k++;
	}
}

void	initialiser(char tab[4][5], int x_pos, int y_pos)
{
	int i;
	int j;

	while ((tab[0][0] == '.') && (tab[0][1] == '.')
			&& (tab[0][2] == '.') && (tab[0][3] == '.'))
	{
		i = 0;
		while (i <= 2)
		{
			move_up_once(tab, x_pos + i);
			i++;
		}
	}
	while (tab[0][0] == '.' && tab[1][0] == '.'
			&& tab[2][0] == '.' && tab[3][0] == '.')
	{
		j = 0;
		while (j <= 2)
		{
			move_left_once(tab, y_pos + j);
			j++;
		}
	}
}

void	init_each_tetri(t_line **tetri1)
{
	t_line	*tmp;

	tmp = *tetri1;
	while (tmp)
	{
		initialiser(tmp->tetris, 1, 1);
		tmp = tmp->next;
	}
}
