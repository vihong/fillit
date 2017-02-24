/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:14:40 by vi-hong           #+#    #+#             */
/*   Updated: 2017/01/10 10:42:42 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*new;
	int		i;
	int		j;
	int		k;

	str = (char*)s;
	i = 0;
	j = ft_strlen(str) - 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (!s[i])
		return ("");
	while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t' || str[j] == '\0')
		j--;
	new = (char*)malloc(sizeof(char) * (j - i + 2));
	if (new == NULL)
		return (NULL);
	k = 0;
	while (i < j + 1)
		new[k++] = str[i++];
	new[k] = '\0';
	return (new);
}
