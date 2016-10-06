/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:53:13 by apinho            #+#    #+#             */
/*   Updated: 2016/10/06 17:18:19 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*getvarenv(t_tout *tout, char *var)
{
	t_double	*gogo;

	gogo = tout->env->head;
	if (gogo)
	{
		while (gogo)
		{
			if (ft_strncmp(gogo->s, var, ft_strlen(var)) == 0)
				return (gogo->s);
			gogo = gogo->next;
		}
	}
	return (NULL);
}

void	normegocd(t_tout *tout)
{
	if (tout->homecd)
		tout->lines[1] = ft_strjoinfree(tout->lines[1], tout->homecd, 1);
	if (access(tout->lines[1], F_OK) == 0)
	{
		if (access(tout->lines[1], X_OK) == 0)
		{
			chdir(tout->lines[1]);
			maj_oldpwd(tout);
		}
		else
		{
			ft_putstr("cd: permission denied: ");
			ft_putendl(tout->lines[1]);
		}
	}
	else
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(tout->lines[1]);
	}
}

void	gocd(t_tout *tout)
{
	char	*buff;

	buff = NULL;
	tout->homecd = NULL;
	tout->oldpwd2 = getcwd(buff, 42);
	tout->oldpwd = ft_strjoin(tout->oldpwd2, "/");
	free(tout->oldpwd2);
	if (!tout->lines[1])
		tout->lines[1] = ft_strdup(getvarenv(tout, "HOME") + 5);
	else if (ft_strncmp(tout->lines[1], "~", 1) == 0)
	{
		if (ft_strlen(tout->lines[1]) > 1)
			tout->homecd = ft_strdup(tout->lines[1] + 1);
		free(tout->lines[1]);
		tout->lines[1] = ft_strdup(getvarenv(tout, "HOME") + 5);
	}
	else if (ft_strncmp(tout->lines[1], "-", 1) == 0)
	{
		free(tout->lines[1]);
		tout->lines[1] = ft_strdup(getvarenv(tout, "OLDPWD") + 7);
	}
	gocd2(tout);
}

void	gocd2(t_tout *tout)
{
	if (tout->lines[1] && access(tout->lines[1], F_OK) == 0)
		normegocd(tout);
	else if (tout->lines[1])
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(tout->lines[1]);
	}
	else
		maj_oldpwd(tout);
	free(tout->oldpwd);
	free(tout->homecd);
}

void	maj_oldpwd(t_tout *tout)
{
	t_double	*gogo;

	if (getvarenv(tout, "OLDPWD") == NULL)
		setit(tout->env, "OLDPWD", ft_strjoin("OLDPWD=", tout->oldpwd));
	else
	{
		gogo = tout->env->head;
		if (gogo)
		{
			while (gogo)
			{
				if (ft_strncmp(gogo->s, "OLDPWD", 6) == 0)
				{
					ft_strdel(&gogo->s);
					gogo->s = ft_strjoin("OLDPWD=", tout->oldpwd);
					return ;
				}
				gogo = gogo->next;
			}
		}
	}
}
