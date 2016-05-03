/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:58:13 by apinho            #+#    #+#             */
/*   Updated: 2016/05/03 15:05:53 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	normefork1lol(t_tout *tout, char *cmd)
{
	pid_t papa;

	papa = fork();
	if (papa == -1)
	{
		ft_putstr("Fork Error");
		exit(EXIT_FAILURE);
	}
	if (papa == 0)
		execve(cmd, tout->lines, tout->envcpy);
	if (papa > 0)
		waitpid(papa, NULL, WCONTINUED);
}

void	accessfork(t_tout *tout, struct stat sb, char *cmd)
{
	if (access(cmd, X_OK) == 0)
	{
		if (S_ISDIR(sb.st_mode))
		{
			ft_putstr(cmd);
			ft_putendl(" is a directory");
		}
		else
			normefork1lol(tout, cmd);
	}
	else
	{
		ft_putstr("minishell: permission denied: ");
		ft_putendl(tout->cmd);
	}
}

int		normefork2lol(t_tout *tout, int i, char *cmd)
{
	struct stat	sb;

	while (tout->path[++i])
	{
		if (ft_strncmp(tout->cmd, "./", 2) == 0 || \
				(ft_strncmp(tout->cmd, "/", 1) == 0))
			cmd = tout->cmd;
		else
			cmd = ft_strjoinchar(tout->path[i], tout->cmd, '/');
		stat(cmd, &sb);
		if (access(cmd, F_OK) == 0)
		{
			accessfork(tout, sb, cmd);
			break ;
		}
	}
	return (i);
}

void	dothefork(t_tout *tout)
{
	int		i;
	char	*cmd;

	cmd = NULL;
	tout->envcpy = lst_to_tab(tout);
	i = -1;
	if (ft_getenv(tout->envcpy, "PATH=") == NULL)
		tout->path = ft_strsplit(" : ", ':');
	else
		tout->path = ft_strsplit(ft_getenv(tout->envcpy, "PATH="), ':');
	i = normefork2lol(tout, i, cmd);
	if (tout->path[i] == NULL)
	{
		ft_putstr("minishell: command not found: ");
		ft_putendl(tout->cmd);
	}
}

int		is_str_alnum(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isalnum(str[i])))
			return (0);
		i++;
	}
	return (1);
}
