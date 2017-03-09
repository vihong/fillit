/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_or_not.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 01:23:36 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/09 02:47:12 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_place(char **sq, int sq_size, char tetri[4][5], int pos)
{
	int m_start;
	int n_start;
	int i;
	int j;

	m_start = pos / sq_size;
	n_start = pos % sq_size;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri[i][j] != '.')
				if (sq[m_start + i][n_start + j] != '.')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void		put_tetri(char **sq, int sq_size, char tetri[4][5], int pos)
{
	int m_start;
	int n_start;
	int i;
	int j;

	m_start = pos / sq_size;
	n_start = pos % sq_size;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri[i][j] != '.')
				sq[m_start + i][n_start + j] = tetri[i][j];
			j++;
		}
		i++;
	}
}

void		remove_tetri(char **sq, int sq_size, char tetri[4][5], int pos)
{
	int m_start;
	int n_start;
	int i;
	int j;

	m_start = pos / sq_size;
	n_start = pos % sq_size;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri[i][j] != '.')
				sq[m_start + i][n_start + j] = '.';
			j++;
		}
		i++;
	}
}
