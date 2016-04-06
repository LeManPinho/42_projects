char  *ft_getenvpath(char **env, char *elem)
{
  int i;
  int u;
  
  i = 0;
  while (env[i])
  {
    u = 0;
    while (u < ft_strlen(elem) && u >= 0)
    {
      if (env[i][u] != elem[u])
        u = -1;
      else
        u++;
    }
    if (u == ft_strlen(elem))
      return (&env[i]);
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
  
  while (93)
  {
  	i = 0;
    ft_putstr("$> ");
    get_next_line(0, &line);
    lines = ft_strsplit(line, ' ');
    cmd = ft_strdup(lines[0]);
    pathrecup = ft_getenvpath(env, "PATH="));
    path =ft_strsplit(pathrecup, ':');
    while (path[i])
    	execve(ft_strjoinslash(path[i], cmd), lines, env);
  }
  
}
