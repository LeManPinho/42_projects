/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:21:24 by hjacque           #+#    #+#             */
/*   Updated: 2016/04/02 16:29:12 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft/libft.h"

int		indexof(const char *str, const char c)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

void	pathmalloc(int i, int ac, char **av, char **path)
{
	int		k;

	k = -1;
	while (i < ac)
	{
		if (!(path[++k] = malloc(ft_strlen(av[i]) + 1)))
			return ;
		path[k] = av[i];
		i++;
	}
}

int		getargopt(int ac, char **av, int *state, char **path)
{
	t_stock	n;

	n.p = -1;
	while (++n.p < 10)
		state[n.p] = 0;
	n.i = 1;
	while (n.i < ac && av[n.i][0] == '-')
	{
		n.u = 0;
		while (av[n.i][++n.u])
		{
			n.p = indexof("lRartgofdu", av[n.i][n.u]);
			if (n.p != -1)
				state[n.p] = 1;
			else if (n.p == -1)
			{
				printerror(av, n.i, n.u);
				return (-1);
			}
		}
		n.i++;
	}
	pathmalloc(n.i, ac, av, path);
	return (0);
}

void	launch(char **path, int *state)
{
	int			i;
	struct stat	mstat;

	i = -1;
	if (path == NULL)
	{
		if (state[D] == 1)
		{
			lstat(".", &(mstat));
			printfile(state, ".", mstat, findmaxfile(".", state, mstat));
		}
		else
			recursive(".", state, 0);
	}
	else
	{
		while (path[++i])
			rilimate(path[i], state, i);
	}
}

int		main(int ac, char **av)
{
	char	**path;
	int		i;
	int		state[10];
	int		k;

	i = 1;
	k = 0;
	while (i < ac && av[i][0] == '-')
		i++;
	while (i < ac)
	{
		k++;
		i++;
	}
	if (k == 0)
		path = NULL;
	else if (!(path = malloc(sizeof(char *) * (k + 1))))
		return (0);
	else
		path[k] = NULL;
	if (getargopt(ac, av, state, path) == -1)
		return (0);
	launch(path, state);
	return (0);
}
