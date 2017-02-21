/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:02:21 by vi-hong           #+#    #+#             */
/*   Updated: 2017/02/21 23:05:39 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char*		buf = NULL;
	t_line*		tetri1;
	char		a = 'A';


	if (argc != 2)
		ft_putstr("usage: ./fillit file\n");
	else
	{
		buf = parsing(argv[1]);
		printf("%s", buf);
		printf("check_input: %d\n", check_input(buf));
		if (check_input(buf) == 0)
		{
			ft_putstr("fichier invalid !\n");
		}
		else
		{
			make_tab(buf, &tetr1, &a);
			initialise(tetri1->tetris, 1, 1);
			aff_lst(&tetri1);
			/* et maintenan intervient le solver*/
		}
	}
	return (0);
}
