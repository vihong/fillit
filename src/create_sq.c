/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 02:08:38 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/09 02:31:26 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_sq(int sq_size)
{
	char	**tab;
	int		i;

	tab = NULL;
	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (sq_size + 1))))
		return (NULL);
	while (i <= sq_size)
	{
		*(tab + i) = (char*)malloc(sizeof(char) * (sq_size + 1));
		if (*(tab + i) == NULL)
			return (0);
		i++;
	}
	ft_bzero(tab[--i], sq_size);
	return (tab);
}
