/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 03:33:23 by vi-hong           #+#    #+#             */
/*   Updated: 2017/01/05 06:22:45 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ss1;
	char	*ss2;
	size_t	i;

	ss1 = (char*)s1;
	ss2 = (char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ss1[i] == ss2[i] && i < n - 1)
		i++;
	return ((unsigned char)ss1[i] - (unsigned char)ss2[i]);
}
