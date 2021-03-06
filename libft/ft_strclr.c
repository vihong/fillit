/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:16:45 by vi-hong           #+#    #+#             */
/*   Updated: 2017/01/09 19:33:57 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			s[i] = '\0';
			i++;
		}
		s[i] = '\0';
	}
}
