/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 19:47:21 by vi-hong           #+#    #+#             */
/*   Updated: 2017/02/21 21:15:34 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "fillit.h"


void	make_tab(char* buf, t_line** tetri, char* letter )
{
	char	tab[4][5];
	int		start_index = 0;
	char*	tmp;
	int		k = 0;
	int		nb_tetri = 2;



	for (nb_tetri = 4; nb_tetri != 0; nb_tetri--, start_index++)
	{
		k = 0;
		tmp = ft_strsub(buf, start_index * 21, 20);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 5 ; j++, k++)
			{
				tab[i][j] = tmp[k];
			}	
		k++;
//		print_tab(tab);
		add_tetrim(tetri, letter, tab);
	}
}

int		main()
{
	char	a = 'X';
	char*	buf1 = "AA..\nA...\nA...\n....\n\n....\n....\n....\nBBBB\n\n....\nC...\nCCC.\n....\n\n....\nDD..\n.DD.\n....\n";
	t_line*		tetri1;
	t_line*		tmp;


	make_tab(buf1, &tetri1, &a);
	

	printf("\n\nInitialisation de chacune des instances:\n");


	tmp = tetri1;
	while (tmp)
	{
		initialiser(tmp->tetris, 1, 1);
	//	aff_lst(&tetri1);
		tmp = tmp->next;
	}


/*
	initialiser(tetri1->tetris, 1, 1);
	initialiser((tetri1->next)->tetris, 1, 1);
	initialiser(((tetri1->next)->next)->tetris, 1, 1);
*/
	
	aff_lst(&tetri1);
	return (0);
}


