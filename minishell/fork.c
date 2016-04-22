#include "minishell.h"

void	dothefork(t_tout *tout)
{
	pid_t 	papa;
	int		i;

	i = -1;
	while (tout->path[++i])
	{
		papa = fork();
		if (papa == -1)
		{
			ft_putstr("Fork Error");
			exit(EXIT_FAILURE);
		}
		if (papa == 0)
		{
			execve(ft_strjoinchar(tout->path[i], tout->cmd, '/'), tout->lines, tout->envcpy);
			exit(EXIT_SUCCESS);
		}
		if (papa > 0)
			wait(NULL);
	}
}

int		is_str_alnum(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isalnum(str[i])))
			return (0);
		i++;
	}
	return (1);
}