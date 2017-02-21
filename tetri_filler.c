/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_filler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:52:18 by vi-hong           #+#    #+#             */
/*   Updated: 2017/02/16 19:09:50 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef	struct s_list t_list;

struct	s_list
{
	char			tab[4][5];
	char			letter;
	struct s_list*	next;
};

/*
void	t_list_filler(char tab)
{

}
*/

/*
void	print_t_list(t_list* node)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			printf("%c", tab[i][j]);
}
*/

/*
int		main()
{
	char	tab[4][6] = {	[0] = "AA..\n",
							[1] = ".A..\n",
							[2] = ".A..\n",
							[3] = "....\n"		
						};

	
	// Je rempli mon instance avec les données contenues dans tab[4][6]
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			tetri1.tab[i][j] = tab[i][j];

	// Je print les données de mon instance une à une
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			printf("%c", tetri1.tab[i][j]);
	return (0);
}
*/

int		ft_strlen(char* str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

int		main()
{
	char	buf[] = "AA..\n.A..\n.A..\n....\n\nBBBB\n....\n....\n....\n";

	int len_buf = ft_strlen(buf);
	int k = 0;
	int indice = 1;
	
	t_list tetri1;
	t_list tetri2;
	tetri1.next = &tetri2;

	while (k < len_buf)
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 5 && k < indice * 21; j++, k++)
				tetri1.tab[i][j] = buf[k];

	
	
		printf("k = %d\n", k);
		k++;
		printf("k = %d\n", k);
	
	
	
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 5 && k < indice * 21; j++, k++)
				tetri2.tab[i][j] = buf[k];
		k++;
	}
	//Je print les données de mon instance une à une
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			printf("%c", tetri1.tab[i][j]);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			printf("%c", tetri2.tab[i][j]);
	return (0);
}

