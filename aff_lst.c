/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 22:17:13 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/14 17:00:23 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_tab(char tab[4][5])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		i++;
	}
}

void	print_sq(char **sq, int sq_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < sq_size)
	{
		j = 0;
		while (j < sq_size)
		{
			ft_putchar(sq[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	aff_lst(t_line **tetris)
{
	t_line	*tmp;

	tmp = *tetris;
	while (tmp != NULL)
	{
		print_tab(tmp->tetris);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
