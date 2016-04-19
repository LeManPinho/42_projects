#include "minishell.h"

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

char  *ft_getenv(char **env, char *elem)
{
  int i;
  unsigned int u;
  int o;
  
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

t_tout  *inittout(char **env)
{
	t_tout *tout;
	int     i;
	
	i = 0;
	if (!(tout = (t_tout *)malloc(sizeof(t_tout))))
		return (NULL);
	tout->envcpy = ft_tabdup(env);
	tout->cmd = NULL;
	tout->env = new_dlst();
	while (env[i])
		dlst_addbackw(tout->env, dlst_allelem(env[i++]));
	tout->path = ft_strsplit(ft_getenv(tout->envcpy, "PATH="), ':');
	return (tout);
}

int   main(int ac, char **av, char **env)
{
	t_tout    *tout;
	int		i;
	pid_t 	papa;
  
	(void)ac;
	(void)av;
	tout = inittout(env);
	while (93)
	{
		i = -1;
		ft_putstr("$> ");
		get_next_line(0, &(tout->line));
		if (ft_strcmp(tout->line, "\0") == 0)
			wait(NULL);
		else
		{
			tout->lines = ft_strsplit(tout->line, ' ');
			tout->cmd = ft_strdup(tout->lines[0]);
			if (ft_strcmp(tout->cmd, "setenv") == 0)
				setenvnow(tout);
			if (ft_strcmp(tout->cmd, "unsetenv") == 0)
				unsetenvnow(tout);
			if (ft_strcmp(tout->cmd, "env") == 0)
				printenv(tout);
			if (ft_strcmp(tout->cmd, "cd") == 0)
				gocd(tout);
			while (tout->path[++i])
			{
				if (ft_strcmp(tout->cmd, "exit") == 0)
					return (0);
				papa = fork();
				if (papa == -1)
				{
					ft_putstr("fork");
					exit(EXIT_FAILURE);
				}
				if (papa == 0)
				{
					execve(ft_strjoinchar(tout->path[i], tout->cmd, '/'), tout->lines, tout->envcpy);
					exit(EXIT_SUCCESS);
				}
				if (papa > 0)
					wait(NULL);
			}
		}
	}
  return (0);
}
