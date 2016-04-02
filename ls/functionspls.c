/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionspls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 14:35:10 by apinho            #+#    #+#             */
/*   Updated: 2016/04/02 16:29:19 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printerror(char **av, int i, int u)
{
	ft_putstr("./ft_ls: illegal option -- ");
	ft_putchar(av[i][u]);
	ft_putchar('\n');
	ft_putendl("usage: ./ft_ls [-Radfglortu] [file ...]");
}

void	gopath(char *path, int *state, struct stat stat, int i)
{
	DIR		*yolo;

	if (!(yolo = opendir(path)))
	{
		ft_putstr("./ft_ls: ");
		perror(path);
	}
	else
	{
		closedir(yolo);
		if (S_ISREG(stat.st_mode) || state[D] == 1)
			printfile(state, path, stat, findmaxfile(path, state, stat));
		else
		{
			if (i > 0)
				write(1, "\n", 1);
			ft_putstr(path);
			ft_putendl(":");
			recursive(path, state, 2);
		}
	}
}

void	gopath2(char *path, int *state, struct stat stat, int i)
{
	if (S_ISREG(stat.st_mode) || state[D] == 1)
		printfile(state, path, stat, findmaxfile(path, state, stat));
	else
	{
		if (i > 0)
			write(1, "\n", 1);
		ft_putstr(path);
		ft_putendl(":");
		recursive(path, state, 2);
	}
}

void	rilimate(char *path, int *state, int i)
{
	struct stat mstat;

	if (lstat(path, &(mstat)) == -1)
	{
		ft_putstr("./ft_ls: ");
		perror(path);
	}
	else if (S_ISREG(mstat.st_mode) || S_ISLNK(mstat.st_mode))
		gopath2(path, state, mstat, i);
	else
		gopath(path, state, mstat, i);
}
