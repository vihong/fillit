/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icampill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:51:16 by icampill          #+#    #+#             */
/*   Updated: 2017/03/09 02:29:50 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_tetris(t_line **new, char tab[4][5])
{
	int i;
	int j;

	i = -1;
	while (i++ < 4)
	{
		j = -1;
		while (j++ < 5)
			(*new)->tetris[i][j] = tab[i][j];
	}
}

void	add_tetri(t_line **tetris, char *letter, char tab[4][5])
{
	t_line	*new;
	t_line	*tmp;

	if (!(new = malloc(sizeof(t_line))))
		return ;
	fill_tetris(&new, tab);
	new->prev = NULL;
	new->next = NULL;
	new->letter = *letter;
	new->pos = 0;
	if (*tetris == NULL)
		*tetris = new;
	else
	{
		tmp = *tetris;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}
