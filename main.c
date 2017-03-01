/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:02:21 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/01 23:29:44 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		main(int argc, char **argv)
{
	char*		buf = NULL;
	t_line*		tetri1;
	t_line*		tmp;
	char**		sq = NULL;
//	int			ind = 0;
	int			nb_tetri;
	int			sq_size;
//	int			pile_tetri = 0;

	if (argc != 2)
		ft_putstr("usage: ./fillit file\n");
	else
	{
		buf = parsing(argv[1]);
		nb_tetri = count_tetri(buf);

//		printf("[ETAPE 1/5] PARSING: SUCCESS\n");
//		printf("%s\n", buf);
		if (check_input(buf) == 0)
		{
		//	ft_putstr("[ETAPE 2/5] CHECKING: FAIL\n\n");
			ft_putstr("error");
			return (0);
		}
		else
		{
		//	printf("[ETAPE 2/5] CHECKING: SUCCESS -- %d TETRI(S)\n\n", nb_tetri);
			make_tab(buf, &tetri1, nb_tetri);
			tmp = tetri1;
			while (tmp)
			{
				initialiser(tmp->tetris, 1, 1);
				tmp = tmp->next;
			}
			printf("[ETAPE 3/5] CONVERSION INTO INSTANCES: SUCCESS\n");
			aff_lst(&tetri1);

			printf("[ETAPE 4/5] SOLVER: to come\n\n");

			sq_size = ft_sqrt((nb_tetri * 4));
			printf("----> sq = %d\n", sq_size);
			while (nb_tetri * 4 > sq_of(sq_size))
				sq_size++;


//			while ()
			sq = create_square(sq_size);

			print_sq(sq, sq_size);
			printf("lulu\n");
			fill_sq(sq, &sq_size, &tetri1, &nb_tetri);
//			sq_size++;

			printf("\nApres remplissage (NOT FINISHED):\n");
			print_sq(sq, sq_size);
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
