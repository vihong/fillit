/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 02:16:22 by vi-hong           #+#    #+#             */
/*   Updated: 2017/01/05 02:24:35 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*ss1;
	char	*ss2;
	size_t	i;
	size_t	j;

	ss1 = (char*)s1;
	ss2 = (char*)s2;
	i = 0;
	j = 0;
	while (ss1[i])
		i++;
	while (ss2[j] && j < n)
	{
		ss1[i] = ss2[j];
		i++;
		j++;
	}
	ss1[i] = '\0';
	return (ss1);
}
