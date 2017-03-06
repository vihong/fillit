/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 19:37:05 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/06 21:04:59 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_with_dots(char** sq, int* sq_size)
{
	for (int i = 0; i < *sq_size; i++)
		for (int j = 0 ; j < *sq_size; j++)
			sq[i][j] = '.';
}


int		fill_sq(char** sq, int* sq_size, t_line** tetri1, int* nb_tetri)
{
	int			ind = 0;
	t_line*		tmp;
	int			pile_tetri = *nb_tetri;

	fill_with_dots(sq, sq_size);
	printf("pile_tetri: %d (at start)\n\n" , pile_tetri);

	tmp = *tetri1;
	tmp->ind = 0;

	if (pile_tetri == 0)
	{
		printf("j'ai placé tous les tetris\n");
		return 1;
	}

	while (ind < ((*sq_size) * (*sq_size))/* && pile_tetri != 0*/ )
	{
		printf("ind (début): %d\n", ind);
		if (check_place(sq, *sq_size, tmp->tetris, ind) == 0 && (ind == sq_of(*sq_size) - 1))
		{
			printf("Je n'ai pas réussi à placer l'instance %c à ind = %d\n", tmp->letter, tmp->ind);
		//	if (tmp->prev == NULL)
		//	{
		//		printf("épuisé toutes les poss\n");
		//		
		//		return 0;
		//	}
			if (tmp->prev != NULL)
				tmp = tmp->prev;
			printf("Je reviens à l'instance %c situé à ind = %d\n", tmp->letter, tmp->ind);
			remove_tetri(sq, *sq_size, tmp->tetris, tmp->ind);
			printf("Je remove l'instance %c situé à l'ind %d\n", tmp->letter, tmp->ind);
			pile_tetri++;
			printf("ind:%d\n", ind);
			tmp->ind++;
			printf("J'essaie de placer %c à ind = %d\n", tmp->letter, tmp->ind);
			ind = -1;
			if (tmp->ind == sq_of(*sq_size))
				break;
		}
		
		print_sq(sq, *sq_size);	
		if (check_place(sq, *sq_size, tmp->tetris, tmp->ind) == 1)
		{
			put_tetri(sq, *sq_size, tmp->tetris, tmp->ind);
			printf("!!!!! Je place l'instance %c à tmp->ind = %d!!!!\n", tmp->letter, tmp->ind);
		//	tmp->ind = ind;
			pile_tetri--;
			printf("pile_tetri: %d\n", pile_tetri);
			tmp = tmp->next;
			printf("J'essaie maintenant de placer l'instance %c\n", tmp->letter);
			printf("tmp->ind:%d\n", tmp->ind);
			printf("ind:%d\n", ind);
			ind = -1;
		}
		ind++;
	}
	printf("Sortie while\n");
	if (/*ind == sq_of(*sq_size) && */pile_tetri == 0)
		return 1;
	else
		return 0;
}
