/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icampill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:51:16 by icampill          #+#    #+#             */
/*   Updated: 2017/02/24 19:33:12 by vi-hong          ###   ########.fr       */
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

void add_tetrim(t_line **tetris, char *letter, char tab[4][5])
{
	t_line 	*new;
	t_line 	*tmp;

	new = malloc(sizeof(t_line));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			new->tetris[i][j] = tab[i][j];
//	print_tab(new->tetris);

	new->next = NULL;
//	new->letter = *letter;
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

/*
int main ()
{
	char *str;
	t_line *salut;
	char c;
	
	c = 'd';
	str = "bonjours\nffffff\nffffffff\nfffffff\nfffffffff\nffffffffff\nfffffffffff\nfffffffffff\nffffffff\n";

	count_tetri(str);
	add_tetrim(&salut, &c);
	aff_lst(&salut);
}
*/
