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
	char	*oldpwd;
}               t_tout;


void		normefork1lol(t_tout *tout, char *cmd);
int		normefork2lol(t_tout *tout, int i, char *cmd);
void		normefork21lol(t_tout *tout, char *cmd);
int		normefork22lol(t_tout *tout, int i, char *cmd);
void		normegocd(t_tout *tout);
void		normegocd_i(t_tout *tout);
int			isallspace(char *str);
t_dlst		*new_dlst(void);
t_double	*dlst_allelem(char *elem);
t_dlst		*dlst_addbackw(t_dlst *dlst, t_double *dble);
t_dlst		*dlst_delelem(t_dlst *dlst, char *elemdel);
int			maj_dlst(t_dlst *dlst, t_double *elem);
char		*ft_getenv(char **env, char *elem);
void		setenvnow(t_tout *tout);
void		unsetenvnow(t_tout *tout);
t_dlst		*setit(t_dlst *dlst, char *elem, char *modifelem);
void		printenv(t_tout *tout);
char		*getvarenv(t_tout *tout, char *var);
void		gocd(t_tout *tout);
void		maj_oldpwd(t_tout *tout);
int			tests(t_tout *tout);
void		dothefork(t_tout *tout);
int			is_str_alnum(char *str);
char		**lst_to_tab(t_tout *tout);
void		free_tab(char **tab, int size);
void		dothefork2(t_tout *tout);
char		**env_i_stuff(t_tout *tout);
int			tests_i(t_tout *tout);
void		gocd_i(t_tout *tout);
void		printenvtab(char **tab);

#endif
