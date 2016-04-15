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
# include "get_next_line.h"

typedef struct      s_double
{
  char              *s;
  struct s_double   *next;
  struct s_double   *prev;
}                   t_double;

typedef struct      s_dlst
{
    struct s_double *head;
    struct s_double *tail;
    size_t          lenght;
}                   t_dlst;

typedef struct  s_tout
{
    t_dlst   *env;
    char    *line;
    char    **lines;
    char    *cmd;
    char    **path;
    char    **envcpy;
}               t_tout;

t_dlst  *new_dlst(void);
t_double    *dlst_allelem(char *elem);
t_dlst  *dlst_addbackw(t_dlst *dlst, t_double *dble);
t_dlst  *dlst_delelem(t_dlst *dlst, char *elemdel);
int     maj_dlst(t_dlst *dlst, t_double *elem);
char    *ft_getenv(char **env, char *elem);

#endif
