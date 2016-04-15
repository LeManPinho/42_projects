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
        return ;
    tout->envcpy = ft_tabdup(env);
    tout->cmd = NULL;
    tout->env = new_dlst();
    while (env[i])
        dlst_addbackw(tout->env, dlst_allelem(env[i++]));
    return (tout);
}

int   main(int ac, char **av, char **env)
{
        t_tout    *tout;
	char  	*line;
	char	*pathrecup;
	char	**lines;
	char	*cmd;
	char	**path;
	int		i;
	char	**envcpy;
 	pid_t 	papa;
  
	(void)ac;
	(void)av;
        tout = inittout(env);
	envcpy = ft_tabdup(env);
	while (93)
	{
		i = -1;
		ft_putstr("$> ");
		get_next_line(0, &line);
		if (ft_strcmp(line, "\0") == 0)
			wait(NULL);
		else
		{
			lines = ft_strsplit(line, ' ');
			cmd = ft_strdup(lines[0]);
			pathrecup = ft_getenv(envcpy, "PATH=");
			path = ft_strsplit(pathrecup, ':');
			if (ft_strcmp(cmd, "env") == 0)
				ft_puttab(envcpy);
			while (path[++i])
			{
				if (ft_strcmp(cmd, "exit") == 0)
					return (0);
				papa = fork();
				if (papa == -1)
				{
					ft_putstr("fork");
					exit(EXIT_FAILURE);
				}
				if (papa == 0)
				{
					execve(ft_strjoinslash(path[i], cmd), lines, envcpy);
					exit(EXIT_SUCCESS);
				}
				if (papa > 0)
					wait(NULL);
//		if (access(path[i], F_OK) == -1)
//			printerroraccess(); //fonction pour later
//		else
//			execve(ft_strjoinslash(path[i], cmd), lines, envcpy);
			}
		}
	}
  return (0);
}
