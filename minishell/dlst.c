#include "minishell.h"

t_dlst  *new_dlst(void)
{
    t_dlst *new;
    
    new = (t_dlst*)malloc(sizeof(t_dlst));
    if (new != NULL)
    {
        new->head = NULL;
        new->tail = NULL;
        new->lenght = 0;
    }
    return (new);
}

t_double    *dlst_allelem(char *elem)
{
    t_double *data;
    
    data = (t_double*)malloc(sizeof(t_double))
    if (data != NULL)
    {
        data->s = ft_strdup(elem);
        data->next = NULL;
        data->prev = NULL;
    }
    return (data);
}

t_dlst  *dlst_addbackw(t_dlst *dlst, t_double *double)
{
    if (dlst && double)
    {
        if (dlst->tail == NULL)
        {
            dlst->head = double;
            dlst->tail = double;
        }
        else
        {
            dlst->tail->next = double;
            double->prev = dlst->tail;
            dlst->tail = double;
        }
        dlst->lenght++;
    }
    return (dlst);
}

t_dlst  *dlst_delelem(t_dlst *dlst, char *elemdel)
{
        t_double *tmp;
        int     i;
        
        i = 0;
        if (dlst)
            while (tmp && !i)
            {
                if (ft_strcmp(tmp->s, elemdel, ft_strlen(elemdel)) == 0)
                {
                    if (!tmp->next && !tmp->prev)
                    {
                        ft_strdel(&dlst->head->s);
                        free(dlst);
                    }
                    else
                        i = maj_dlst(dlst, tmp);
                    dlst->lenght--;
                    free(tmp);
                }
                tmp = tmp->next;
            }
        return (lst);
}

int     maj_dlst(t_dlst *dlst, t_double *elem)
{
    if (!elem->next && elem->prev)
    {
        dlst->tail = elem->prev;
        dlst->tail->next = NULL;
        ft_strdel(&elem->s);
    }
    else if (!elem->prev && elem->next)
    {
        dlst->head = elem->next;
        dlst->head->prev = NULL;
        ft_strdel(&elem->s);
    }
    else
    {
        elem->prev->next = elem->next;
        elem->next->prev = elem->prev;
        ft_strdel(&elem->s);
    }
    dlst->lenght--;
    return (1);
}