/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 02:08:38 by vi-hong           #+#    #+#             */
/*   Updated: 2017/02/25 02:29:18 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define SQ_SIZE 10


	// Donne lui une dimension et il te crée un carré de cette même dimension. 
char**	create_square(int square_size)
{
	char**	tab = NULL;


	tab = malloc(sizeof(char*) * (square_size + 1));
	if (tab == NULL)
		return 0;

	for (int i = 0; i < square_size; i++)
	{
		*(tab + i)  = (char*)malloc(sizeof(char) * (square_size + 1));
		if (*(tab + i) == NULL)
			return (0);
	}
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
			sq[i][j] = 'x';

	for (int i = 0; i < SQ_SIZE; i++)
	{
		for (int j = 0; j < SQ_SIZE; j++)
			printf("%c", sq[i][j]);
		printf("\n");
	}
	return (0);
}
*/
