/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 19:37:05 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/01 19:47:19 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


fill_sq(char** sq, int sq_size, **t_line tetri1, int nb_tetri)
{
	int		ind = 0;

	sq_size = ft_sqrt((nb_tetri * 4));
	printf("----> sq = %d\n", sq_size);
	while (nb_tetri * 4 > sq_of(sq_size))
		sq_size++;
//	while (ind != sq_size * sq_size)
//	{
	sq = create_square(sq_size);
	for (int i = 0; i < sq_size; i++)
		for (int j = 0 ; j < sq_size; j++)
			sq[i][j] = '.';

	printf("\nAvant remplissage:\n");
	print_sq(sq, sq_size);
	printf("pile_tetri (at start): %d\n", pile_tetri);
	tmp = tetri1;
	while (ind < (sq_size * sq_size) && tmp && pile_tetri != 0)
	{
		printf("ind: %d\n", ind);

		if (check_place(sq, sq_size, tmp->tetris, ind) == 1)
		{
			put_tetri(sq, sq_size, tmp->tetris, ind);
			pile_tetri--;
			printf("pile_tetri: %d\n", pile_tetri);
			tmp = tmp->next;
			ind = 0;
		}

		ind++;
	}
}
