/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 01:25:49 by vi-hong           #+#    #+#             */
/*   Updated: 2017/02/25 01:47:40 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


char**	create_tab(void)
{
	char**	tab = NULL;

	tab = malloc(sizeof(char*) * (4 + 1));
	if (tab == NULL)
		return 0;

	for (int i = 0; i < 5; i++)
	{
		*(tab + i)  = (char*)malloc(sizeof(char) * (5 + 1));
		if (*(tab + i) == NULL)
			return (0);
	}
	return (tab);
}

int		main()
{
	char**	tab = NULL;

	tab = create_tab();
	
	for (int i = 0; i < 4; i++)
		for (int j = 0 ; j < 5; j++)
			tab[i][j] = 'x';

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%c", tab[i][j]);
		printf("\n");
	}
	return (0);
}
