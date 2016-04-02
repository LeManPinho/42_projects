/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:36:37 by hjacque           #+#    #+#             */
/*   Updated: 2016/04/02 11:55:33 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		classtime(void *a, void *b)
{
	int	c;
	int	d;

	c = ((t_osef *)a)->my_stat.st_mtime * 1000 +\
		((t_osef *)a)->my_stat.st_mtimespec.tv_nsec / 1000000;
	d = ((t_osef *)b)->my_stat.st_mtime * 1000 +\
		((t_osef *)b)->my_stat.st_mtimespec.tv_nsec / 1000000;
	if (c > d)
		return (-1);
	else if (d == c)
		return (0);
	else
		return (1);
}

int		classtimerev(void *a, void *b)
{
	int	c;
	int	d;

	c = ((t_osef *)a)->my_stat.st_mtime * 1000 +\
		((t_osef *)a)->my_stat.st_mtimespec.tv_nsec / 1000000;
	d = ((t_osef *)b)->my_stat.st_mtime * 1000 +\
		((t_osef *)b)->my_stat.st_mtimespec.tv_nsec / 1000000;
	if (d > c)
		return (-1);
	else if (d == c)
		return (0);
	else
		return (1);
}

int		classalpha(void *a, void *b)
{
	int	j;

	j = ft_strcmp(((t_osef *)a)->name, ((t_osef *)b)->name);
	return (j);
}

int		classalpharev(void *a, void *b)
{
	return (-(ft_strcmp(((t_osef *)a)->name, ((t_osef *)b)->name)));
}

t_max	findmax(t_ls *l, char *path, int *state)
{
	t_info	*lol;
	t_max	maxlen;

	maxlen.mlinks = 0;
	maxlen.muser = 0;
	maxlen.mgrp = 0;
	maxlen.mbytes = 0;
	while (l != NULL)
	{
		lol = fullinfo(((t_osef *)l->data)->my_stat,\
			ft_strjoinslash(path, ((t_osef *)l->data)->name), state);
		getmaxlen(lol, &maxlen, state);
		l = l->next;
	}
	return (maxlen);
}
