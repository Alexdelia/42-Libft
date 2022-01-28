/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fld_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:54:03 by adelille          #+#    #+#             */
/*   Updated: 2022/01/28 19:15:02 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fld.h"

t_fldc	*fld_new(void)
{
	t_fldc	*new;

	new = (t_fldc *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->p = NULL;
	new->next = NULL;
	return (new);
}

bool	fld_addback(t_fldc **alst, t_fldc *new)
{
	t_fldc	*last;

	if (!new || !alst)
		return (false);
	if (*alst)
	{
		last = fld_last(*alst);
		last->next = new;
	}
	else
		*alst = new;
	return (true);
}

t_fldc	*fld_last(t_fldc *fldc)
{
	while (fldc)
	{
		if (!fldc->next)
			return (fldc);
		fldc = fldc->next;
	}
	return (fldc);
}

bool	fld_clear(t_fldc **fldc)
{
	t_fldc	*tmp;

	if (!fldc || !*fldc)
		return (false);
	while (*fldc)
	{
		tmp = (*fldc)->next;
		free((*fldc)->p);
		free(*fldc);
		*fldc = tmp;
	}
	return (false);
}
