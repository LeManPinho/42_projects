#include "minishell.h"

void	dothefork(t_tout *tout)
{
	pid_t 	papa;
	int		i;
	char *cmd;

	tout->envcpy = lst_to_tab(tout);
	i = -1;
	if (ft_getenv(tout->envcpy, "PATH=") == NULL)
		tout->path = ft_strsplit(" : ", ':');
	else
		tout->path = ft_strsplit(ft_getenv(tout->envcpy, "PATH="), ':');
	while (tout->path[++i])
	{
		if (ft_strncmp(tout->cmd, "./", 2) == 0 || (ft_strncmp(tout->cmd, "/", 1) == 0))
			cmd = tout->cmd;
		else
			cmd = ft_strjoinchar(tout->path[i], tout->cmd, '/');
		if (access(cmd, F_OK) == 0)
		{
			if (access(cmd, X_OK) == 0)
			{
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
			else
			{
				ft_putstr("minishell: permission denied: ");
				ft_putendl(tout->cmd);
			}
			break ;
		}
	}
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

void	dothefork2(t_tout *tout)
{
	pid_t 	papa;
	int		i;
	char *cmd;

	free_tab(tout->envcpy, ft_tablen(tout->envcpy));
	tout->envcpy = env_i_stuff(tout);
	i = -1;
	if (ft_getenv(tout->envcpy, "PATH=") == NULL)
		tout->path = ft_strsplit(" : ", ':');
	else
		tout->path = ft_strsplit(ft_getenv(tout->envcpy, "PATH="), ':');
	while (tout->path[++i])
	{
		if (ft_strncmp(tout->lines[ft_tablen(tout->lines) - 1], "./", 2) == 0 || (ft_strncmp(tout->lines[ft_tablen(tout->lines) - 1], "/", 1) == 0))
			cmd = tout->lines[ft_tablen(tout->lines) - 1];
		else
			cmd = ft_strjoinchar(tout->path[i], tout->lines[ft_tablen(tout->lines) - 1], '/');
		if (access(cmd, F_OK) == 0)
		{
			if (access(cmd, X_OK) == 0)
			{
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
			else
			{
				ft_putstr("minishell: permission denied: ");
				ft_putendl(tout->cmd);
			}
			break ;
		}
	}
	if (tout->path[i] == NULL)
	{
		ft_putstr("minishell: command not found: ");
		ft_putendl(tout->cmd);
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