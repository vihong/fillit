/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 22:17:13 by vi-hong           #+#    #+#             */
/*   Updated: 2017/02/24 22:18:22 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


void	print_tab(char tab[4][5])
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			printf("%c", tab[i][j]);
	printf("\n");
}



void aff_lst(t_line **tetris)
{
	t_line	*tmp;

	tmp = *tetris;
	while (tmp != NULL)
	{
		print_tab(tmp->tetris);
//		printf("letter = %c\n", tmp->letter);
		tmp = tmp->next;
	}
}
