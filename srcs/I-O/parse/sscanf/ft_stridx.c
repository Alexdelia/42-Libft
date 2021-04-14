/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stridx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:44:25 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 16:49:31 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ft_stridx(const char *str, int c)
{
	register int	i;
	register char	ch;

	i = 0;
	ch = (char)c;
	while (str[i])
	{
		if (s[i] == ch)
			return (i);
		++i;
	}
	return (c ? -1 : i);
}

int	ft_strnidx(const char *str, int c, size_t n)
{
	register int	i;
	register char	ch;

	i = 0;
	ch = (char)c;
	while ((str[i]) && (n--))
	{
		if (str[i] == ch)
			return (i);
		++i;
	}
	return ((c || str[i]) ? -1 : i);
}
