#include "minishell.h"

int     isallspace(char *str)
{
    unsigned int i;
    
    i = 0;
    while (str[i] == ' ')
        i++;
    if (i == (ft_strlen(str)))
        return (1);
    else
        return (0);
    
}