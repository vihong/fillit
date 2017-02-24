/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:14:45 by vi-hong           #+#    #+#             */
/*   Updated: 2017/01/06 14:35:07 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	start;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	tab = (char**)malloc(sizeof(char*) * (ft_strlen(s) + 1));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[start])
			tab[j++] = ft_strsub(s, start, i - start);
	}
	tab[j] = NULL;
	return (tab);
}
