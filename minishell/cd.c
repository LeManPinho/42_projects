#include "minishell.h"

char	*getvarenv(t_tout *tout, char *var)
{
	t_double	*gogo;

	gogo = tout->env->head;
	if (gogo)
	{
		while (gogo)
		{
			if (ft_strncmp(gogo->s, var, ft_strlen(var)) == 0)
				return (gogo->s);
			gogo = gogo->next;
		}
	}
	return (NULL);
}

void	gocd(t_tout *tout)
{
	char	*buff;

	buff = NULL;
	tout->oldpwd = getcwd(buff, 42);
	tout->oldpwd = ft_strjoin(tout->oldpwd, "/");
	if (!tout->lines[1])
		tout->lines[1] = ft_strdup(getvarenv(tout, "HOME") + 5);
	else if (ft_strncmp(tout->lines[1], "-", 1) == 0)
		tout->lines[1] = ft_strdup(getvarenv(tout, "OLDPWD") + 7);
	if (access(tout->lines[1], F_OK) == 0)
	{
		chdir(tout->lines[1]);
		maj_oldpwd(tout);
	}
}

void	maj_oldpwd(t_tout *tout)
{
	t_double	*gogo;

	gogo = tout->env->head;
	if (gogo)
	{
		while (gogo)
		{
			if (ft_strncmp(gogo->s, "OLDPWD", 6) == 0)
			{
				ft_strdel(&gogo->s);
				gogo->s = ft_strjoin("OLDPWD=", tout->oldpwd);
				return ;
			}
			gogo = gogo->next;
		}
	}
}