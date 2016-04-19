#include "minishell.h"

void	setenv(t_dlst *tout)
{
	setit(tout->env, tout->lines[2], ft_strjoinchar(tout->lines[2], tout->lines[3], '='));
}

void	unsetenv(t_tout *tout)
{
	dlst_delelem(tout->env, tout->lines[2]);
}

t_dlst  *setit(t_dlst *dlst, char *elem, char *modifelem)
{
		t_double *tmp;
		int     i;
		
		tmp = dlst->head;
		if (dlst)
		{
			while (tmp)
			{
				if (ft_strncmp(tmp->s, elem, ft_strlen(elem)) == 0)
				{
					ft_strdel(&tmp->s);
					tmp->s = ft_strdup(modifelem);
					return (dlst);
				}
				tmp = tmp->next;
			}
			dlst_addbackw(dlst, dlst_allelem(elem));
		}
		return (dlst);
}

void	printenv(t_tout *tout)
{
	t_double	*gogo;

	gogo = tout->env->head;
	if (gogo)
	{
		while (gogo)
		{
			ft_putendl(gogo->s);
			gogo = gogo->next;
		}
	}
}
