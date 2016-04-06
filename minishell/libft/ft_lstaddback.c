/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacque <hjacque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 01:55:29 by hjacque           #+#    #+#             */
/*   Updated: 2015/01/06 19:41:24 by hjacque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list *alst, t_list *new)
{
	if (alst && new)
	{
		while (alst->next != NULL)
			alst = alst->next;
		alst->next = new;
	}
}
