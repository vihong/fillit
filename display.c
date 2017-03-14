/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 22:16:07 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/10 14:49:22 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_tab(char tab[4][5])
{
	int i;
	int j;

	i = -1;
	while (i++ < 4)
	{
		j = -1;
		while (j++ < 5)
			ft_putchar(tab[i][j]);
	}
}

void	print_sq(char **sq, int sq_size)
{
	int i;
	int j;

	i = -1;
	while (i++ < sq_size - 1)
	{
		j = -1;
		while (j++ < sq_size - 1)
			ft_putchar(sq[i][j]);
		ft_putchar('\n');
	}
}
