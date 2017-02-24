/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 23:33:36 by vi-hong           #+#    #+#             */
/*   Updated: 2017/02/24 19:52:51 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fillit.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);	
}

// man check_input : "si input non valide renvoie 0, sinon 1".

int		check_input(char *str)
{
	int i;
	int w;
	int lettre;
	int nb_tetri;
	int count_char;

	w = 0;
	i = 0;
	count_char = 0;
	lettre = 0;
	if (!*str)
		return (0);
	while (str[i] == '\n' || (str[i] == '#') || str[i] == '.')
	{
//		printf("cc = %d\n", count_char); 
		if (count_char == 19)
		{
//			printf("je rentre\n");
			count_char = -1;
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
//			printf("lettre = %d\n", lettre);
//			printf("str[i] = %d\n\n", i);
			if (lettre % 4 > 3)
			{
//				printf("str[i] = %d\n", i);
//				printf("lettre = %d\n", lettre);
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
//	printf("lettre ===> %d\n", lettre);
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

/*
int main ()
{
	int i;
	char *str;

//	str = "##..\n....\n....\n..##\n";
	str = "....\n...#\n...#\n...#\n\n....\n....\n....\n...#\n\n.###\n...#\n....\n....\n\n....\n..##\n.##.\n....\n";
//	str = "AA..\n.AA.\n....\n....\n\n..BB\n..BB\n....\n....\n\nCCCC\n....\n....\n....\n";
	i = 0;
	printf("%s\n", str);
	printf("\nchech_input: %d\n", check_input(str));
	return (0);
}
*/

// error 1: fichier vide --> OK !
// error 1: fichier avec plus de 26 tetriminos --> à faire
// error 2: autre chose que des dieses --> OK !
// error 3: plus de 4 diese --> OK !
// error 4: mauvais tetrimos : il ne se touche pas par ex
// error 5: tetri mis en dernière ligne : aurait du fonctionner
// // 

