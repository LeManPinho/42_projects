t_list	*addelem(t_list **begin, void *data)
{
	t_list	*ret;

	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	ret->data = data;
	ret->next = *begin;
	*begin = ret;
	return (ret);
}

t_list   *dtab_to_lst(char **dtab)
{
    t_list   *lst;
    int     i;
    
    i = -1;
    lst = NULL;
    while (dtab[++i])
        addelem(&lst, dtab[i]);
    return (lst);
}
