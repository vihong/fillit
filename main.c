/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:02:21 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/14 18:25:12 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char		*buf;
	t_line		*tetri1;
	char		**sq;
	int			sq_size;

	buf = NULL;
	sq = NULL;
	if (ac != 2)
		ft_putstr("usage: ./fillit file\n");
	else
	{
		buf = parsing(av[1]);
		if (check_input(buf) == 0)
		{
			ft_putstr("error\n");
			return (0);
		}
		make_tab(buf, &tetri1, count_tetri(buf));
		init_each_tetri(&tetri1);
		sq_size = get_closest_sq_size(count_tetri(buf));
		sq = get_smallest_sq(sq, &sq_size, &tetri1);
		print_sq(sq, --sq_size);
	}
	return (0);
}
