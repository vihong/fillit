/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:07:15 by vi-hong           #+#    #+#             */
/*   Updated: 2017/02/21 19:13:04 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_swap(char* a, char* b)
{
	char c;

	c = *a;
	*a = *b;
	*b = c;
}

void	move_up_once(char tab[4][5], int x_pos)
{
	int i = x_pos;
	int k = 0;

	for (k = 0; tab[i][k] && k < 4; k++)
		ft_swap(&tab[i][k], &tab[i -1][k]);
}


void	move_left_once(char tab[4][5], int y_pos)
{
	int j = y_pos;
	int k = 0;

	for (k = 0; tab[k][j] && k < 4; k++)
		ft_swap(&tab[k][j], &tab[k][j - 1]);
}


void	initialiser(char tab[4][5], int x_pos, int y_pos)
{
	int i = 0;
	int j = 0;

	while ((tab[0][0] == '.') && (tab[0][1] == '.') && (tab[0][2] == '.') && (tab[0][3] == '.'))
	{
		i = 0;
		for (i = 0; i <= 2; i++ )
			move_up_once(tab, x_pos + i);
	}
	while (tab[0][0] == '.' && tab[1][0] == '.' && tab[2][0] == '.' && tab[3][0] == '.')
	{
		j = 0;
		for (j = 0; j <= 2; j++)
			move_left_once(tab, y_pos + j);
	}
}
