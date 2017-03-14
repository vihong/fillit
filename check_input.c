/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:52:57 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/14 16:49:23 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tetri_valid(char* buf_sub)
{
	int i = 0;
	int hashtag = 0;
	int nb_contact = 0;

//	printf("*********Test tetri valid**********\n");
	while (buf_sub[i])
	{
//		printf("i: %d\n", i);
		if (buf_sub[i] == '#')
		{
			hashtag++;
//			printf("-------nb of hash: %d\n", hashtag);
/*			if (hashtag == 4)
				break ;
			if (	(buf_sub[i + 1] == '#') || (buf_sub[i - 1] == '#') ||
					(buf_sub[i + 5] == '#') || (buf_sub[i - 5] == '#'))
			{
				nb_contact++;
			}*/
			if (buf_sub[i] == '#')
			{
				if (buf_sub[i + 1] == '#')
					nb_contact++;
				if (buf_sub[i - 1] == '#')
					nb_contact++;
				if (buf_sub[i + 5] == '#')
					nb_contact++;
				if (buf_sub[i - 5] == '#')
					nb_contact++;
			}
//			printf("nb_contact: %d\n", nb_contact);
			if (hashtag == 4)
			   if (nb_contact >= 6)
				return (1);

		}
		i++;
	}
//	printf("nb_contact: %d\n", nb_contact);
//	printf("This is the end\n");
	return (0);
}


int		check_input(char *buf)
{
	int i = 0;
	int count_char = 0;
	int hashtag = 0;
	int b_slash = 0;

	while (buf[i] == '.' || buf[i] == '#' || buf[i] == '\n')
	{
		if (buf[i] == '#')
			hashtag++;
		if (buf[i] == '\n')
			b_slash++;
//		printf("hashtag: %d\n", hashtag);
//		printf("b_slash: %d\n", b_slash);
//		printf("count_char: %d\n\n", count_char);
		if (count_char % 19 == 0 && buf[i] == '\n' && hashtag == 4 && b_slash == 4)
		{
//			printf("i (in): %d\n", i);
//			printf("hashtag (in): %d\n", hashtag);


			if (buf[i + 1] == '\0' && (tetri_valid(ft_strsub(buf, i - 19, 19)) == 1) )
				return (1);
//			printf("e-jaunet est café\n");
			if (tetri_valid(ft_strsub(buf, i - 19, 19)) != 1 || buf[i + 1] != '\n')
				return (0);
			count_char = -2;
			hashtag = 0;
			b_slash = -1;
		}
		count_char++;
		i++;	
	}
//	printf("cc: %d\n", count_char);
//	printf("buf[i] = %c\n", buf[i]);
	return (0);
}

/*
int		main()
{
	char*	buf = "####\n....\n....\n....\n";

	printf("%s\n", buf);
	check_input(buf) == 0 ? printf("buf invalid\n") : printf("buf valid\n");
	return (0);
}
*/
