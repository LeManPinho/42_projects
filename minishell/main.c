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

t_dlst  *new_dlst(void)
{
    t_dlst *new;
    
    new = (t_dlst*)malloc(sizeof(t_dlst));
    if (new != NULL)
    {
        new->head = NULL;
        new->tail = NULL;
        new->lenght = 0;
    }
    return (new);
}

t_double    *dlst_allelem(char *elem)
{
    t_double *data;
    
    data = (t_double*)malloc(sizeof(t_double))
    if (data != NULL)
    {
        data->s = ft_strdup(elem);
        data->next = NULL;
        data->prev = NULL;
    }
    return (data);
}

t_dlst  *dlst_addbackw(t_dlst *dlst, t_double *double)
{
    if (dlst && double)
    {
        if (dlst->tail == NULL)
        {
            dlst->head = double;
            dlst->tail = double;
        }
        else
        {
            dlst->tail->next = double;
            double->prev = dlst->tail;
            dlst->tail = double;
        }
        dlst->lenght++;
    }
    return (dlst);
}

t_dlst  *dlst_delelem(t_dlst *dlst, char *elemdel)
{
        t_double *tmp;
        int     i;
        
        i = 0;
        if (dlst)
            while (tmp && !i)
            {
                if (ft_strcmp(tmp->s, elemdel, ft_strlen(elemdel)) == 0)
                {
                    if (!tmp->next && !tmp->prev)
                    {
                        ft_strdel(&dlst->head->s);
                        free(dlst);
                    }
                    else
                        i = maj_dlst(dlst, tmp);
                    dlst->lenght--;
                    free(tmp);
                }
                tmp = tmp->next;
            }
        return (lst);
}

int     maj_dlst(t_dlst *dlst, t_double *elem)
{
    if (!elem->next && elem->prev)
    {
        dlst->tail = elem->prev;
        dlst->tail->next = NULL;
        ft_strdel(&elem->s);
    }
    else if (!elem->prev && elem->next)
    {
        dlst->head = elem->next;
        dlst->head->prev = NULL;
        ft_strdel(&elem->s);
    }
    else
    {
        elem->prev->next = elem->next;
        elem->next->prev = elem->prev;
        ft_strdel(&elem->s);
    }
    dlst->lenght--;
    return (1);
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
