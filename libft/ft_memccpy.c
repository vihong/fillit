/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 03:46:58 by vi-hong           #+#    #+#             */
/*   Updated: 2017/01/10 10:35:01 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n)
{
	unsigned char	*src1;
	unsigned char	*dst1;
	unsigned char	c1;
	size_t			i;

	i = 0;
	src1 = (unsigned char*)s;
	dst1 = (unsigned char*)d;
	c1 = (unsigned char)c;
	while (i < n && src1[i] != c1)
	{
		dst1[i] = src1[i];
		i++;
	}
	if (i != n && src1[i] == c1)
	{
		dst1[i] = src1[i];
		return (dst1 + i + 1);
	}
	return (NULL);
}
