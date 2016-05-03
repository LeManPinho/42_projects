/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isallspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 14:31:22 by apinho            #+#    #+#             */
/*   Updated: 2016/05/03 15:09:46 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		isallspace(char *str)
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
