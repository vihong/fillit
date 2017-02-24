/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icampill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:51:16 by icampill          #+#    #+#             */
/*   Updated: 2017/02/25 00:24:14 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void add_tetri(t_line **tetris, char *letter, char tab[4][5])
{
	t_line 	*new;
	t_line 	*tmp;

	new = malloc(sizeof(t_line));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			new->tetris[i][j] = tab[i][j];


	new->next = NULL;
	new->letter = *letter;
	if (*tetris == NULL)
		*tetris = new;
	else
	{
		tmp = *tetris;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
