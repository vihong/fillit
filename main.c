/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:02:21 by vi-hong           #+#    #+#             */
/*   Updated: 2017/02/24 19:44:31 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char*		buf = NULL;
	t_line*		tetri1;
	t_line*		tmp;
	char		a = 'A';
	int			nb_tetri;


	if (argc != 2)
		ft_putstr("usage: ./fillit file\n");
	else
	{
		buf = parsing(argv[1]);
		nb_tetri = count_tetri(buf);
		printf("1) PARSING: SUCCESS\n");
		printf("%s\n", buf);
		if (check_input(buf) == 0)
		{
			ft_putstr("2) CHECKING: FAIL\n\n");
			return (0);
		}
		else
		{
			printf("2) CHECKING: SUCCESS -- %d TETRI(S)\n", nb_tetri);
			make_tab(buf, &tetri1, nb_tetri);
			tmp = tetri1;
			while (tmp)
			{
				initialiser(tmp->tetris, 1, 1);
				tmp = tmp->next;
			}
			aff_lst(&tetri1);
		}
	}
	return (0);
}
