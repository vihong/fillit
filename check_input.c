/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi-hong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:52:57 by vi-hong           #+#    #+#             */
/*   Updated: 2017/03/14 18:43:20 by vi-hong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	increaser(char *buf, int i, int *hashtag, int *b_slash)
{
	if (buf[i] == '#')
		(*hashtag)++;
	if (buf[i] == '\n')
		(*b_slash)++;
}

void	var_cleaner(int *count_char, int *hashtag, int *b_slash)
{
	*count_char = -2;
	*hashtag = 0;
	*b_slash = -1;
}

void	contact_counter(char *buf_sub, int i, int *nb_contact)
{
	if (buf_sub[i + 1] == '#')
		(*nb_contact)++;
	if (buf_sub[i - 1] == '#')
		(*nb_contact)++;
	if (buf_sub[i + 5] == '#')
		(*nb_contact)++;
	if (buf_sub[i - 5] == '#')
		(*nb_contact)++;
}

int		t_valid(char *buf_sub)
{
	int		i;
	int		hashtag;
	int		nb_contact;

	i = 0;
	hashtag = 0;
	nb_contact = 0;
	while (buf_sub[i])
	{
		if (buf_sub[i] == '#')
		{
			hashtag++;
			if (buf_sub[i] == '#')
				contact_counter(buf_sub, i, &nb_contact);
			if (hashtag == 4 && nb_contact >= 6)
				return (1);
		}
		i++;
	}
	return (0);
}

int		check_input(char *buf)
{
	int		i;
	int		count_char;
	int		hashtag;
	int		b_slash;

	i = 0;
	count_char = 0;
	hashtag = 0;
	b_slash = 0;
	while (buf[i] == '.' || buf[i] == '#' || buf[i] == '\n')
	{
		increaser(buf, i, &hashtag, &b_slash);
		if (count_char % 19 == 0 && hashtag == 4 && b_slash == 4)
		{
			if (buf[i + 1] == '\0' && (t_valid(ft_strsub(buf, i - 19, 19))))
				return (1);
			if (!(t_valid(ft_strsub(buf, i - 19, 19))) || buf[i + 1] != '\n')
				return (0);
			var_cleaner(&count_char, &hashtag, &b_slash);
		}
		count_char++;
		i++;
	}
	return (0);
}
