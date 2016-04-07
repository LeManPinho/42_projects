#include "minishell.h"

char  *ft_getenvpath(char **env, char *elem)
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

int   main(int ac, char **av, char **env)
{
  char  *line;
  char	*pathrecup;
  char	**lines;
  char	*cmd;
  char	**path;
  int	i;
  char	**envcpy;
  pid_t papa;
  
  (void)ac;
  (void)av;
  envcpy = ft_tabdup(env);
  while (93)
  {
  	i = -1;
    ft_putstr("$> ");
    get_next_line(0, &line);
    lines = ft_strsplit(line, ' ');
    cmd = ft_strdup(lines[0]);
    pathrecup = ft_getenvpath(envcpy, "PATH=");
    path = ft_strsplit(pathrecup, ':');
    while (path[++i])
    {
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
//		if (access(path[i], F_OK) == -1)
//			printerroraccess(); //fonction pour later
//		else
//			execve(ft_strjoinslash(path[i], cmd), lines, envcpy);
	}
  }
  return (0);
}
