/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 15:30:20 by apinho            #+#    #+#             */
/*   Updated: 2016/04/02 12:14:49 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		printfile(int *state, char *path, struct stat stat, t_max maxlen)
{
	t_info	*lol;

	if ((state[L] == 1) || (state[G] == 1) || (state[O] == 1))
	{
		lol = fullinfo(stat, path, state);
		printl(lol, maxlen, state, path);
		ft_putstr(path);
	}
	else
		ft_putstr(path);
	ft_putchar('\n');
}

t_max		findmaxfile(char *path, int *state, struct stat stat)
{
	t_info	*lol;
	t_max	maxlen;

	maxlen.mlinks = 0;
	maxlen.muser = 0;
	maxlen.mgrp = 0;
	maxlen.mbytes = 0;
	lol = fullinfo(stat, path, state);
	getmaxlen(lol, &maxlen, state);
	return (maxlen);
}

t_ls		*reverselist(t_ls *a)
{
	t_ls	*temp;
	t_ls	*prev;

	while (a != NULL)
	{
		temp = a->next;
		a->next = prev;
		prev = a;
		a = temp;
	}
	return (prev);
}

int			classtimeaccess(void *a, void *b)
{
	int	c;
	int	d;

	c = ((t_osef *)a)->my_stat.st_atime * 1000 +\
		((t_osef *)a)->my_stat.st_atimespec.tv_nsec / 1000000;
	d = ((t_osef *)b)->my_stat.st_atime * 1000 +\
		((t_osef *)b)->my_stat.st_atimespec.tv_nsec / 1000000;
	if (c > d)
		return (-1);
	else if (d == c)
		return (0);
	else
		return (1);
}

int			classtimeaccessr(void *a, void *b)
{
	int	c;
	int	d;

	c = ((t_osef *)a)->my_stat.st_atime * 1000 +\
		((t_osef *)a)->my_stat.st_atimespec.tv_nsec / 1000000;
	d = ((t_osef *)b)->my_stat.st_atime * 1000 +\
		((t_osef *)b)->my_stat.st_atimespec.tv_nsec / 1000000;
	if (c < d)
		return (-1);
	else if (d == c)
		return (0);
	else
		return (1);
}
