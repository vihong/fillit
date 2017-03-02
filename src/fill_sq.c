/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 19:37:05 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/02 03:03:18 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		fill_sq(char** sq, int* sq_size, t_line** tetri1, int* nb_tetri)
{
	int			ind = 0;
	t_line*		tmp;
	int			pile_tetri = *nb_tetri;

	for (int i = 0; i < *sq_size; i++)
		for (int j = 0 ; j < *sq_size; j++)
			sq[i][j] = '.';
//	printf("\nAvant remplissage:\n");
//	print_sq(sq, *sq_size);
//	printf("pile_tetri: %d (at start)\n" , pile_tetri);
	tmp = *tetri1;
	while (ind < ((*sq_size) * (*sq_size)) && pile_tetri != 0)
	{
//		printf("ind: %d\n", ind);

		if (check_place(sq, *sq_size, tmp->tetris, ind) == 1)
		{
			put_tetri(sq, *sq_size, tmp->tetris, ind);
			pile_tetri--;
			printf("pile_tetri: %d\n", pile_tetri);
			tmp = tmp->next;
			ind = 0;
		}
		ind++;
	}
	if (/*ind == sq_of(*sq_size) && */pile_tetri == 0)
		return 1;
	else
		return 0;
}
