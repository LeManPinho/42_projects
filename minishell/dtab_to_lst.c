#include "minishell.h"

t_lst	*addelem(t_lst **begin, void *data)
{
	t_lst	*ret;

	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	ret->data = data;
	ret->next = *begin;
	*begin = ret;
	return (ret);
}

t_lst   *dtab_to_lst(char **dtab)
{
    t_lst   *lst;
    int     i;
    
    i = -1;
    lst = NULL;
    while (dtab[++i])
        addelem(&lst, dtab[i]);
    return (lst);
}
