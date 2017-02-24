/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 22:51:56 by vi-hong           #+#    #+#             */
/*   Updated: 2017/01/09 18:08:33 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	i = 0;
	if (n == 0 || dst == src)
		return (dst);
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	while (--n)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = s[i];
	return (d);
}
