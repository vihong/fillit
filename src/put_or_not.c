/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_or_not.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 01:23:36 by vi-hong           #+#    #+#             */
/*   Updated: 2017/02/28 04:45:14 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define SQ_SIZE 10
#define INDEX 2

/*renvoie 1 si elle peut placer le tetriminos, ou 0 si elle ne peut pas.*/


// Donne lui le tableau à remplir et un tetri et il te dit s'il peut le mettre dedans (renvoie 1) ou pas (renvoie 0).


void		tetri_copy(char** sq, char tetri[4][5], int m, int n)
{
	int i = 0;
	int j = 0;
	int m_max = m + 4;
	int n_max = n + 4;

	for (i = 0; m < m_max && i < 4; m++, i++)
		for (j = 0; n < n_max && j < 5; j++, n++)
		{
			printf("(m: %d, n: %d) with (i: %d, j: %d) \n\n", m, n, i, j);
			if (n == n_max)
			{
				m++;
				n = n - 3;
				i++;
			}
			sq[m][n] = tetri[i][j];
		}
			
}


void		from_pos_to_coor(int pos)
{
	
}

void		put_tetri(char** sq, char tetri[4][5], int pos)
{
	int i = 0;
	int j = 0;
	int m = 0;
	int n = 0;
	int m_start;
	int n_start;
	int m_max = 0;
	int n_max = 0;
	
	m_start = pos / SQ_SIZE;
	n_start = pos % SQ_SIZE;
	m = 0;
	while (m < SQ_SIZE)
	{
		n = 0;
		while (n < SQ_SIZE)
		{
			if (m == m_start && n == n_start)
			{
				m_max = m + 4;
				while (m < m_max)
				{
					n_max = n + 4;	
					j = 0;
					while (n < n_max && j < 5)
					{
/*						printf("m: %d\n", m);
						printf("n: %d\n", n);
						printf("i: %d\n", i);
						printf("j: %d\n\n", j);
						*/
						if (tetri[i][j] != '.')
						{
							sq[m][n] = tetri[i][j];
						}

						n++;
						j++;
					}
					n = n - 4;
					m++;
					i++;
				}
			}
			n++;
		}
		m++;
	}
}


void	print_sq(char** sq, int sq_size)
{
	for (int i = 0; i < SQ_SIZE; i++)
	{
		for (int j = 0; j < SQ_SIZE; j++)
			printf("%c", sq[i][j]);
		printf("\n");
	}
		
	printf("\n");
}





int		main()
{
	char**	sq = NULL;
	char	tetri[4][5] = { [0] = "AA..",
							[1] = ".A..",
							[2] = ".A..",
							[3] = "...."}; 

	sq = create_square(SQ_SIZE);

	for (int i = 0; i < SQ_SIZE; i++)
		for (int j = 0 ; j < SQ_SIZE; j++)
			sq[i][j] = '.';

	sq[1][6] = 'X';
	printf("Grille à remplir:\n");
	print_sq(sq, SQ_SIZE);
	
	put_tetri(sq, tetri, INDEX);
	printf("Tetriminos:\n");
	print_tab(tetri);

	printf("\n");
	printf("Grille remplie à l'indice %d:\n", INDEX);
	print_sq(sq, SQ_SIZE);



	return (0);
}

