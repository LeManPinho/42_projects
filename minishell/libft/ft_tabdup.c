#include "libft.h"

int		ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**ft_tabdup(char **tab)
{
	char	**ret;
	int		i;

	i = 0;
	ret = (char**)malloc(sizeof(char*) * ft_tablen(tab) + 1);
	while (tab[i])
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
