/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 03:30:00 by vi-hong           #+#    #+#             */
/*   Updated: 2017/01/05 12:02:00 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	d;
	unsigned char	*tmp;

	i = 0;
	d = c;
	tmp = (unsigned char*)s;
	if (n == 0)
		return (NULL);
	while (*tmp != d && i < n - 1)
	{
		tmp++;
		i++;
	}
	if (*tmp == d)
		return (tmp);
	return (NULL);
}
