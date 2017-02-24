/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 04:22:26 by vi-hong           #+#    #+#             */
/*   Updated: 2017/01/10 10:16:37 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *s, size_t len)
{
	size_t		i;
	size_t		j;
	char		*big;
	char		*small;

	i = 0;
	big = (char*)b;
	small = (char*)s;
	if (!*small)
		return ((char*)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == small[j] && i + j < len)
		{
			j++;
			if (small[j] == '\0')
				return ((char*)big + i);
		}
		i++;
	}
	return (NULL);
}
