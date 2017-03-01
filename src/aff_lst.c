/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 22:17:13 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/01 19:24:47 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


void	print_tab(char tab[4][5])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
			ft_putchar(tab[i][j]);
	//	ft_putchar('\n');
	}
}

void	print_sq(char** sq, int sq_size)
{
	for (int i = 0; i < sq_size + 1; i++)
	{
		for (int j = 0; j < sq_size; j++)
			ft_putchar(sq[i][j]);
		ft_putchar('\n');
	}
}


void	aff_lst(t_line **tetris)
{
	t_line	*tmp;

	tmp = *tetris;
	while (tmp != NULL)
	{
	//	printf("letter = %c\n", tmp->letter);
		print_tab(tmp->tetris);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
