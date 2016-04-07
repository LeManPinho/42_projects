#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcnt1.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <signal.h>
# include "libft/libft.h"

typedef struct  s_list
{
  void          *data;
  struct s_list *next;
}               t_list;

t_list	*addelem(t_list **begin, void *data);
t_list  *dtab_to_lst(char **dtab);
char    *ft_getenvpath(char **env, char *elem);

#endif
