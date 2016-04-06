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
  while (93)
  {
    ft_putstr("$> ");
    str_to_wordtab(get_next_line(0), ' ');
    ft_getenvpath(env, "PATH"));
      
  }
  
}
