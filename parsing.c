/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:46:56 by vi-hong           #+#    #+#             */
/*   Updated: 2017/01/26 18:37:09 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* malloc evolutif pour créer un buf pile de la taille du fichier entré*/
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


/* fonction qui permet de maipuler le fichier en paramètre via un fd*/
char	*parsing(char *argv)
{
	int		fd;
	char*	buf;

	fd = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("can't open file");
		return (0);
	}
	buf = read_base(fd);
	close(fd);
	if (fd == -1)
	{
		printf("close() failed");
		return (0);
	}
//	ft_putstr(buf);
//	printf("%d\n", fd);
	return (buf);
}
