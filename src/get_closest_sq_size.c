/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest_sq_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 23:57:20 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/09 02:33:15 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_closest_sq_size(int nb_tetri)
{
	int		closest_sq_size;

	closest_sq_size = ft_sqrt((nb_tetri * 4));
	while (nb_tetri * 4 > sq_of(closest_sq_size))
		closest_sq_size++;
	return (closest_sq_size);
}
