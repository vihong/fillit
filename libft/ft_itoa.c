/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:13:53 by vi-hong           #+#    #+#             */
/*   Updated: 2017/01/09 16:22:59 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_nbdigits(int nb)
{
	size_t			count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char				*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	nbr;

	len = ft_nbdigits(n);
	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		len++;
	}
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	str[--len] = nbr % 10 + '0';
	while (nbr /= 10)
		str[--len] = nbr % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
