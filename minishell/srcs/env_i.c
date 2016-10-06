/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:54:23 by apinho            #+#    #+#             */
/*   Updated: 2016/10/06 15:10:12 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		tests_i(t_tout *tout)
{
	if (ft_strcmp(tout->lines[ft_tablen(tout->lines) - 1], "env") == 0)
	{
		free_tab(tout->envcpy);
		tout->envcpy = env_i_stuff(tout);
		printenvtab(tout->envcpy);
		return (1);
	}
	else if ((ft_strcmp(tout->lines[ft_tablen(tout->lines) - 1], "cd") == 0)\
		|| (ft_strcmp(tout->lines[ft_tablen(tout->lines) - 2], "cd") == 0))
	{
		free_tab(tout->envcpy);
		tout->envcpy = env_i_stuff(tout);
		gocd_i(tout);
		return (1);
	}
	return (0);
}

void	normegocd_i(t_tout *tout)
{
	if (tout->lines[ft_tablen(tout->lines) - 1] && \
			access(tout->lines[ft_tablen(tout->lines) - 1], F_OK) == 0)
	{
		if (access(tout->lines[ft_tablen(tout->lines) - 1], X_OK) == 0)
		{
			chdir(tout->lines[ft_tablen(tout->lines) - 1]);
			maj_oldpwd(tout);
		}
		else
		{
			ft_putstr("cd: permission denied: ");
			ft_putendl(tout->lines[ft_tablen(tout->lines) - 1]);
		}
	}
	else if (tout->lines[ft_tablen(tout->lines) - 1])
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(tout->lines[ft_tablen(tout->lines) - 1]);
	}
	else
		maj_oldpwd(tout);
}

void	gocd_i(t_tout *tout)
{
	char	*buff;

	buff = NULL;
	tout->oldpwd = getcwd(buff, 42);
	tout->oldpwd = ft_strjoin(tout->oldpwd, "/");
	if (ft_strcmp(tout->lines[ft_tablen(tout->lines) - 1], "cd") == 0)
	{
		if (ft_getenv(tout->envcpy, "HOME=") == NULL)
			return ;
		tout->lines[ft_tablen(tout->lines) - 1] = \
			ft_strdupfree(ft_getenv(tout->envcpy, "HOME=") + 5);
	}
	else if (ft_strncmp(tout->lines[ft_tablen(tout->lines) - 1], "-", 1) == 0)
	{
		if (ft_getenv(tout->envcpy, "OLDPWD=") == NULL)
			return ;
		tout->lines[ft_tablen(tout->lines) - 1] = \
			ft_strdupfree(ft_getenv(tout->envcpy, "OLDPWD=") + 7);
	}
	normegocd_i(tout);
}

void	printenvtab(char **tab)
{
	int		i;

	i = 0;
	if (tab[i])
	{
		while (tab[i])
		{
			ft_putendl(tab[i]);
			i++;
		}
	}
}
