/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:25:10 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/14 18:25:30 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solver(char **sq, int sq_size, t_line **tetri1, int pos)
{
	t_line *tmp;

	tmp = *tetri1;
	while (pos != sq_size * sq_size)
	{
		if (check_place(sq, sq_size, tmp->tetris, pos) == 1)
		{
			put_tetri(sq, sq_size, tmp->tetris, pos);
			tmp->pos = pos;
			if (tmp->next == NULL)
				return (1);
			if (solver(sq, sq_size, &(tmp->next), 0) == 1
					&& tmp->next != NULL)
				return (1);
		}
		pos++;
	}
	if (tmp->prev != NULL)
		remove_tetri(sq, sq_size, (tmp->prev)->tetris, (tmp->prev)->pos);
	return (0);
}
