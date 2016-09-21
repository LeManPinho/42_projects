/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testecho.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:35:08 by apinho            #+#    #+#             */
/*   Updated: 2016/09/21 23:45:28 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		testecho(t_tout *tout)
{
	if (ft_strcmp(tout->cmd, "echo") == 0)
	{
		echonow(tout);
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}

void	echonow(t_tout *tout)
{
	char	*t;
	size_t	len;

	t = ft_strstr(tout->line, "echo") + 5;
	while (t && *t)
	{
		while (*t && ft_isspace(*t))
			t++;
		len = 0;
		if (*t == '\"')
		{
			t++;
			len = (!ft_strchr(t, '\"')) ? ft_strlen(t) : ft_strchr(t, '\"') - t;
		}
		else
			while (t[len] && !ft_isspace(t[len]))
				len++;
		write(1, t, len);
		t = t + len;
		if (*t)
		{
			write(1, " ", 1);
			t++;
		}
	}
}
