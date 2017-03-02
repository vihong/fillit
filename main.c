/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:02:21 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/02 03:06:38 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		main(int argc, char **argv)
{
	char*		buf = NULL;
	t_line*		tetri1;
	t_line*		tmp;
	char**		sq = NULL;
	int			nb_tetri;
	int			sq_size;
	int			resp_fill_sq = 0;

	if (argc != 2)
		ft_putstr("usage: ./fillit file\n");
	else
	{
		buf = parsing(argv[1]);
		nb_tetri = count_tetri(buf);

		printf("[ETAPE 1/5] PARSING: SUCCESS\n");
		printf("%s\n", buf);
		if (check_input(buf) == 0)
		{
		//	ft_putstr("[ETAPE 2/5] CHECKING: FAIL\n\n");
			ft_putstr("error");
			return (0);
		}
		else
		{
			printf("[ETAPE 2/5] CHECKING: SUCCESS -- %d TETRI(S)\n\n", nb_tetri);
			make_tab(buf, &tetri1, nb_tetri);
			tmp = tetri1;
			while (tmp)
			{
				initialiser(tmp->tetris, 1, 1);
				tmp = tmp->next;
			}
			printf("[ETAPE 3/5] CONVERSION INTO INSTANCES: SUCCESS\n");
			aff_lst(&tetri1);

			printf("[ETAPE 4/5] SOLVER: SUCCESS\n\n");

			sq_size = ft_sqrt((nb_tetri * 4));
		//	printf("----> sq = %d\n", sq_size);
			while (nb_tetri * 4 > sq_of(sq_size))
				sq_size++;


		while (resp_fill_sq != 1)
		{
				sq = create_square(sq_size);
		//		print_sq(sq, sq_size);
				resp_fill_sq = fill_sq(sq, &sq_size, &tetri1, &nb_tetri);
//				printf("pokemon: %d\n", resp_fill_sq);
				sq_size++;
//				sq = create_square(sq_size);
//				print_sq(sq, sq_size);
//				resp_fill_sq = fill_sq(sq, &sq_size, &tetri1, &nb_tetri);
//				printf("pokemon: %d\n", resp_fill_sq);
		}


			printf("\n[ETAPE 5/5] SOLUTION_DISPLAY:\n");
			print_sq(sq, --sq_size);
//			check_place
//				sq_size++
//			if (pile_tetri == 0)
//			{
//				printf("\n\n>> SUCCESS <<\n\n");
//				print_sq(sq, sq_size);
//			}
		}
	}
	return (0);
}
