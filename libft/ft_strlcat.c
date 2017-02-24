/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 02:24:41 by vi-hong           #+#    #+#             */
/*   Updated: 2017/01/09 18:05:42 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	int				j;
	size_t			tmp;

	i = 0;
	j = 0;
	if (size == 0 && src)
		return (ft_strlen(src));
	tmp = ft_strlen(dst);
	while (dst[i])
		i++;
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	if (i <= size - 1)
		return (ft_strlen(src) + tmp);
	else
		return (ft_strlen(src) + size);
}
