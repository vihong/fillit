/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_or_not.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 01:23:36 by vi-hong           #+#    #+#             */
/*   Updated: 2017/02/25 03:57:57 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define SQ_SIZE 5

/*renvoie 1 si elle peut placer le tetriminos, ou 0 si elle ne peut pas.*/


// Donne lui le tableau à remplir et un tetri et il te dit s'il peut le mettre dedans (renvoie 1) ou pas (renvoie 0).


void		put_tetri(char** sq, char tetri[4][5])
{
	int i = 0;
	int j = 0;
	int m = 0;
	int n = 0;

	
	i = 0;
	while (i < SQ_SIZE)
	{
		j = 0 ;
		while(j < SQ_SIZE)
		{
			if (sq[i][j] == '.' && tetri[i][j] == '#')
			{
				while ()
				{
					sq[i][j] = tetri[][];
				}
			}
			j++;
	
		i++;
	}



/*
	for (i = 0, m = 0; i < SQ_SIZE || m < 4; i++)
		for (int j = 0; j < SQ_SIZE || n < 5; j++)
		{
			if (sq[i][j] == '.' && tetri[m][n] == '#')
			{
				sq[i][j] = tetri[m][n];

			}
			else
				j++;
		}
*/	

		
/*	
	for (m = 0; m < SQ_SIZE; m++)
		for (n = 0; n < SQ_SIZE; n++)
		{
			if (sq[m][n] == '.' && tetri[i][j] == '#')
				for (i = 0; i < 4 && m < SQ_SIZE; i++, m++)
					for (j = 0; j < 5 && n < SQ_SIZE; j++, n++)
						sq[m][n] = tetri[i][j];
		}

*/
	/*
	{
		sq[0][0] = tetris[0][0];
	}
	*/
}


int		main()
{
	char**	sq = NULL;
	char	tetri[4][5] = { [0] = "##..",
							[1] = ".#..",
							[2] = ".#..",
							[3] = "....",
							}; 

	sq = create_square(SQ_SIZE);

	for (int i = 0; i < SQ_SIZE; i++)
		for (int j = 0 ; j < SQ_SIZE; j++)
			sq[i][j] = '.';

//	sq[0][0] = 'c';

	put_tetri(sq, tetri);

	for (int i = 0; i < SQ_SIZE; i++)
	{
		for (int j = 0; j < SQ_SIZE; j++)
			printf("%c", sq[i][j]);
		printf("\n");
	}

	ft_putchar('\n');

	print_tab(tetri);
	return (0);
}
