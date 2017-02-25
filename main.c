/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:02:21 by vi-hong           #+#    #+#             */
/*   Updated: 2017/02/25 01:28:31 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char*		buf = NULL;
	t_line*		tetri1;
	t_line*		tmp;

	int			nb_tetri;


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
			ft_putstr("[ETAPE 2/5] CHECKING: FAIL\n\n");
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

			printf("[ETAPE 4/5] SOLVER: to come\n\n");
		}
	}
	return (0);
}
