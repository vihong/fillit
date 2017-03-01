/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 02:08:38 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/01 19:23:15 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define SQ_SIZE 5


	// Donne lui une dimension et il te crée un carré de cette même dimension. 
char**	create_square(int sq_size)
{
	char**	tab = NULL;
	int i = 0;

	tab = (char**)malloc(sizeof(char*) * (sq_size + 1));
	if (tab == NULL)
		return 0;

	for (i = 0; i <= sq_size; i++)
	{
		*(tab + i)  = (char*)malloc(sizeof(char) * (sq_size + 1));
		if (*(tab + i) == NULL)
			return (0);
	}
	ft_bzero(tab[--i], sq_size);
	return (tab);
}

/*
	// Je teste ma fonction ici avec mon main
int		main()
{
	char**	sq = NULL;

	sq = create_square(SQ_SIZE);
	
	for (int i = 0; i < SQ_SIZE; i++)
		for (int j = 0 ; j < SQ_SIZE; j++)
			sq[i][j] = '!';

	for (int i = 0; i < SQ_SIZE; i++)
	{
		for (int j = 0; j < SQ_SIZE; j++)
			printf("%c", sq[i][j]);
		printf("\n");
	}
	return (0);
}
*/
