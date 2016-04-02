/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:20:31 by hjacque           #+#    #+#             */
/*   Updated: 2016/04/02 11:55:14 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursive(char *path, int *state, int n)
{
	struct dirent	*dir;
	DIR				*yolo;
	t_ls			*a;

	pathnames(path, state, n);
	if (!(yolo = opendir(path)))
	{
		ft_putstr("./ft_ls: ");
		perror(path);
	}
	else
	{
		a = NULL;
		while ((dir = readdir(yolo)))
			a = filla(state, a, path, dir);
		closedir(yolo);
		a = sorta(a, state);
		print(a, state, path, findmax(a, path, state));
		recursive2(a, state, path);
	}
}

void	recursive2(t_ls *a, int *state, char *path)
{
	char			*path2;

	if (state[GR] == 1)
	{
		while (a != NULL)
		{
			path2 = ft_strjoinslash(path, ((t_osef *)a->data)->name);
			if (S_ISDIR(((t_osef *)a->data)->my_stat.st_mode) &&\
				(((t_osef *)a->data)->name)[0] != '.')
				recursive(path2, state, 1);
			a = a->next;
			free(path2);
		}
	}
	clearlst(a);
}

t_ls	*sorta(t_ls *a, int *state)
{
	if (state[F] == 1)
		return (reverselist(a));
	else if (state[T] == 0 && state[R] == 0)
		sortlist(&a, classalpha);
	else if (state[T] == 0 && state[R] == 1)
		sortlist(&a, classalpharev);
	else if (state[T] == 1 && state[R] == 0 && state[U] == 1)
		sortlist(&a, classtimeaccess);
	else if (state[T] == 1 && state[R] == 1 && state[U] == 1)
		sortlist(&a, classtimeaccessr);
	else if (state[T] == 1 && state[R] == 0)
		sortlist(&a, classtime);
	else if (state[T] == 1 && state[R] == 1)
		sortlist(&a, classtimerev);
	return (a);
}

void	pathnames(char *path, int *state, int n)
{
	if (state[GR] == 1 && n == 1)
	{
		write(1, "\n", 1);
		ft_putstr(path);
		ft_putendl(":");
	}
}

t_ls	*filla(int *state, t_ls *a, char *path, struct dirent *dir)
{
	t_osef				*osef;

	if (((state[A] == 0 && dir->d_name[0] != '.' &&\
			dir->d_name[0] != 0 &&
				state[F] == 0)) || (((state[A] == 1) ||
					(state[F] == 1)) && dir->d_name[0] != 0))
	{
		if (!(osef = malloc(sizeof(*osef))))
			return (NULL);
		osef->name = ft_strdup(dir->d_name);
		lstat(ft_strjoinslash(path, dir->d_name), &osef->my_stat);
		a = addelem(&a, osef);
	}
	return (a);
}
