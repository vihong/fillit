/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 23:33:36 by vi-hong           #+#    #+#             */
/*   Updated: 2017/02/21 17:00:43 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

	w = 0;
	i = 0;
	lettre = 0;
	if (!*str)
		return (0);
	while (str[i] == '\n' || (str[i] == '#') || str[i] == '.')
	{
		if ((str[i] == '\n' && str[i + 1] == '\0') && (!(w = 19)))
		   return (0);
		if ((str[i] == '\n' && str[i - 1] == '\n' && w != 20))
			return (0);
		if (str[i] == '\n' && str[i - 1] == '\n')
			w = -1;
		if (str[i] == '#')
		{
			lettre++;
			if (lettre > 4)
				return (0);
			else if (!(str[i + 1] == '#') || (str[i - 1] == '#') ||
				(str[i + 5] == '#') || (str[i - 5] == '#'))
				return (0);
		}
		i++;
		w++;
	}
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}


int main ()
{
	int i;
	char *str;

//	str = "";
	str = "##..\n....\n....\n..##\n";
//	str = "AA..\n.AA.\n....\n....\n\n..BB\n..BB\n....\n....\n\nCCCC\n....\n....\n....\n";
	i = 0;
	printf("%s\n", str);
	printf("\nchech_input: %d\n", check_input(str));
	return (0);
}


// error 1: fichier vide --> OK !
// error 2: autre chose que des dieses --> OK !
// error 3: plus de 4 diese --> OK !
// error 4: mauvais tetrimos : il ne se touche pas par ex
//
//
