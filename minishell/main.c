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

t_list *ft_list_add(void *data, t_list **begin)
{
	t_list *l;
	
	if (!(l = malloc(sizeof(*ret))))
		RETURN (NULL);
	l->data = data;
	l->next = *begin;
	*begin = l;
	return (l);
}

t_list	*listenv(char **envcpy, int size)
{
	t_list *l;
	int i;
	
	i = -1;
	l = 0;
	while (++i < size)
		l = ft_list_add(envcpy[i], l);
	return (l);
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
  
  envcpy = ft_tabdup(env);
  while (93)
  {
  	i = -1;
    ft_putstr("$> ");
    get_next_line(0, &line);
    lines = ft_strsplit(line, ' ');
    cmd = ft_strdup(lines[0]);
    pathrecup = ft_getenvpath(envcpy, "PATH="));
    path = ft_strsplit(pathrecup, ':');
    while (path[++i])
    {
		if (access(path[i], F_OK) == -1)
			printerroraccess(); //fonction pour later
		else
			execve(ft_strjoinslash(path[i], cmd), lines, envcpy);
    }
    papa = fork();
    if (papa == -1)
    {
    	perror("fork");
    	exit(EXIT_FAILURE);
    }
    if (papa == 0)
    {
    	
    	exit(EXIT_SUCCESS);
    }
  }
  return (0);
}
