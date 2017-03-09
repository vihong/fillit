/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 23:33:36 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/08 23:11:33 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
int		error_nb_hashtag(char* str)
{

}


int		error_nb_char(char* str)
{

}


int		error_nb_new_line(char* str)
{

}

int		error_nb_char(char* str)
{

}

int		error_nb_char(char* str)
{

}
*/

int		check_input(char *str)
{
	int i;
	int w;
	int lettre;
	int count_char;

	w = 0;
	i = 0;
	count_char = 0;
	lettre = 0;
	if (!*str)
		return (0);
	if (count_tetri(str) > 26)
		return (0);
	while (str[i] == '\n' || (str[i] == '#') || str[i] == '.')
	{
		if (count_char == 19)
		{
			count_char = -2;
			if (lettre != 4)
			{
				printf("error 0\n");
				printf("lettre = %d\n", lettre);
				printf("str[i] = %d\n\n", i);
				return 0;
			}
		}
		if ((str[i] == '\n' && str[i + 1] == '\0') && (!(w = 19)))
		{
		 	printf("error 1");
		  	return (0);
		}
		if ((str[i] == '\n' && str[i - 1] == '\n' && w != 20))
		{
		 	printf("error 2");
		  	return (0);
		}
		if (str[i] == '\n' && str[i - 1] == '\n')
			w = -1;
		if (str[i] == '#')
		{
			lettre++;

			if (lettre % 4 > 3)
			{
				printf("error 3");
				return (0);
			}
			else if (!((str[i + 1] == '#') || (str[i - 1] == '#') ||
				(str[i + 5] == '#') || (str[i - 5] == '#')))
				{
					printf("error 4");
					printf("str[i] = %d\n", i);
					return (0);
				}
		}
		if (lettre == 4 && str[i] == '\n' && str[i + 1] == '\n')
			lettre = 0;
		i++;
		w++;
		count_char++;

	}
	if (lettre != 4)
	{
		printf("error 5: trop de dièses!");
		printf("str[i] = %d\n", i);
		return 0;
	}
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}
