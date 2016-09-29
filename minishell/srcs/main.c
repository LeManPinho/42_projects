/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:53:25 by apinho            #+#    #+#             */
/*   Updated: 2016/09/26 14:11:51 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_puttab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

char	*ft_getenv(char **env, char *elem)
{
	int				i;
	unsigned int	u;
	int				o;

	i = 0;
	while (env[i])
	{
		u = 0;
		o = 0;
		while (u < ft_strlen(elem) && o != -1)
		{
			if (env[i][u] != elem[u])
				o = -1;
			else
				u++;
		}
		if (u == ft_strlen(elem))
			return (env[i]);
		else
			i++;
	}
	return (NULL);
}

t_tout	*inittout(char **env)
{
	t_tout	*tout;
	int		i;

	i = 0;
	if (!(tout = (t_tout *)malloc(sizeof(t_tout))))
		return (NULL);
	tout->envcpy = ft_tabdup(env);
	tout->cmd = NULL;
	tout->env = new_dlst();
	tout->line = NULL;
	while (env[i])
		dlst_addbackw(tout->env, dlst_allelem(env[i++]));
	return (tout);
}

int		tests(t_tout *tout)
{
	if (ft_strcmp(tout->cmd, "setenv") == 0)
	{
		setenvnow(tout);
		return (1);
	}
	else if (ft_strcmp(tout->cmd, "unsetenv") == 0)
	{
		unsetenvnow(tout);
		return (1);
	}
	else if (ft_strcmp(tout->cmd, "env") == 0)
	{
		if (!(tout->lines[1]))
			printenv(tout);
		else if (ft_strcmp(tout->lines[1], "-i") == 0 && tout->lines[2])
			if (tests_i(tout) == 0)
				dothefork2(tout);
		return (1);
	}
	else if (ft_strcmp(tout->cmd, "cd") == 0)
	{
		gocd(tout);
		return (1);
	}
	return (0);
}

int		main(int ac, char **av, char **env)
{
	t_tout	*tout;
	char	*epured;

	(void)ac;
	(void)av;
	tout = inittout(env);
	while (93)
	{
		ft_putstr("$> ");
		get_next_line(0, &(tout->line));
		if ((ft_strcmp(tout->line, "\0") == 0) || (isallspace(tout->line) == 1))
			;
		else
		{
			epured = epur_str(ft_strdup(tout->line));
			tout->lines = ft_strsplit(epured, ' ');
			tout->cmd = ft_strdup(tout->lines[0]);
			if (ft_strcmp(tout->cmd, "exit") == 0)
				return (0);
			if (tests(tout) == 0 && testecho(tout) == 0)
				dothefork(tout);
		}
	}
	return (0);
}