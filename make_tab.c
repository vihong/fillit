/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 19:47:21 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/09 02:41:56 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		fill_with_letter(char *tmp, char tab[4][5], char *lettre, int *k)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			if (tmp[*k] == '#')
				tab[i][j] = *lettre;
			else
				tab[i][j] = tmp[*k];
			j++;
			(*k)++;
		}
		i++;
	}
}

void		make_tab(char *buf, t_line **tetri, int nb_tetri)
{
	char	tab[4][5];
	int		start_index;
	char	*tmp;
	int		k;
	char	lettre;

	start_index = 0;
	k = 0;
	lettre = 'A';
	while (nb_tetri != 0)
	{
		k = 0;
		tmp = ft_strsub(buf, start_index * 21, 20);
		fill_with_letter(tmp, tab, &lettre, &k);
		add_tetri(tetri, &lettre, tab);
		k++;
		lettre++;
		nb_tetri--;
		start_index++;
	}
}
