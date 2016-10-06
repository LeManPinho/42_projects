/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:59:07 by apinho            #+#    #+#             */
/*   Updated: 2016/10/05 19:08:31 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	normefork21lol(t_tout *tout, char *cmd)
{
	pid_t	papa;

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

void	accessfork_i(t_tout *tout, struct stat sb, char *cmd)
{
	if (access(cmd, X_OK) == 0)
	{
		if (S_ISDIR(sb.st_mode))
		{
			ft_putstr(cmd);
			ft_putendl(" is a directory");
		}
		else
			normefork21lol(tout, cmd);
	}
	else
	{
		ft_putstr("minishell: permission denied: ");
		ft_putendl(tout->lines[ft_tablen(tout->lines) - 1]);
	}
}

int		normefork22lol(t_tout *tout, int i, char *cmd)
{
	struct stat	sb;

	while (tout->path[++i])
	{
		if (ft_strncmp(tout->lines[ft_tablen(tout->lines) - 1], "./", 2) == 0\
			|| (ft_strncmp(tout->lines[ft_tablen(tout->lines) - 1], "/", 1)\
				== 0))
			cmd = tout->lines[ft_tablen(tout->lines) - 1];
		else
			cmd = ft_strjoinchar(tout->path[i], \
					tout->lines[ft_tablen(tout->lines) - 1], '/');
		stat(cmd, &sb);
		if (access(cmd, F_OK) == 0)
		{
			accessfork_i(tout, sb, cmd);
			break ;
		}
	}
	return (i);
}

void	dothefork2(t_tout *tout)
{
	int		i;
	char	*cmd;

	cmd = NULL;
	free_tab(tout->envcpy);
	tout->envcpy = env_i_stuff(tout);
	i = -1;
	if (ft_getenv(tout->envcpy, "PATH=") == NULL)
		tout->path = ft_strsplit(" : ", ':');
	else
		tout->path = ft_strsplit(ft_getenv(tout->envcpy, "PATH="), ':');
	i = normefork22lol(tout, i, cmd);
	if (tout->path[i] == NULL)
	{
		ft_putstr("minishell: command not found: ");
		ft_putendl(tout->lines[ft_tablen(tout->lines) - 1]);
	}
}

char	**env_i_stuff(t_tout *tout)
{
	char	**ret;
	int		i;

	i = 2;
	ret = (char**)malloc(sizeof(char*) * ft_tablen(tout->lines) - 2);
	while (i < ft_tablen(tout->lines) - 1)
	{
		ret[i - 2] = ft_strdup(tout->lines[i]);
		i++;
	}
	ret[i - 2] = NULL;
	return (ret);
}
