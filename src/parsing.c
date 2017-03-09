/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:46:56 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/09 02:43:42 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_base(int fd)
{
	char	buf[2];
	char	*dest;
	char	*tmp;
	int		i;

	if (!(dest = (char*)malloc(sizeof(char) + 1)))
		return (0);
	if (!(tmp = (char*)malloc(sizeof(char) + 1)))
		return (0);
	i = 1;
	while (read(fd, buf, 1))
	{
		buf[1] = '\0';
		free(tmp);
		if (!(tmp = (char*)malloc(sizeof(char) * (i + 1))))
			return (0);
		ft_strcpy(tmp, dest);
		free(dest);
		if (!(dest = (char*)malloc(sizeof(char) * (i + 1))))
			return (0);
		ft_strcpy(dest, tmp);
		dest = ft_strcat(dest, buf);
		i++;
	}
	return (dest);
}

char	*parsing(char *argv)
{
	int		fd;
	char	*buf;

	fd = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("can't open file");
		return (0);
	}
	buf = read_base(fd);
	close(fd);
	if (fd == -1)
	{
		ft_putendl("close() failed");
		return (0);
	}
	return (buf);
}
