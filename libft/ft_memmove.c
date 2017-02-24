/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 03:23:12 by vi-hong           #+#    #+#             */
/*   Updated: 2017/01/05 06:05:39 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char*)dst;
	s = (char*)src;
	i = 0;
	if (s < d)
		while ((int)--len >= 0)
		{
			*(d + len) = *(s + len);
		}
	else
		while (i < len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	return (d);
}
