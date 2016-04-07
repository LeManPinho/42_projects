#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <signal.h>
# include "libft/libft.h"

typedef struct  s_lst
{
  void          *data;
  struct s_lst  *next;
}               t_lst;

t_lst	*addelem(t_lst **begin, void *data);
t_lst  *dtab_to_lst(char **dtab);
char    *ft_getenvpath(char **env, char *elem);

#endif
