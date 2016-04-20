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
			ft_putstr("error fork");
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