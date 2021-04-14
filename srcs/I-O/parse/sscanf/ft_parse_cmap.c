/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:54:51 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 16:55:22 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

const char	*ft_parse_cmap(const char *str,
		unsigned long *num, t_cmap cm, int len)
{
	register int	i;

	*num = 0;
	i = 0;
	while ((*str) && (len-- > 0) &&
		((i = ft_strnidx(cm.cmap, (int)(*str), (size_t)cm.base)) >= 0))
	{
		*num = (*num * (unsigned long)cm.base) + (unsigned long)(i);
		str++;
	}
	return (str);
}

const char	*ft_parsej_cmap(const char *str,
		uintmax_t *num, t_cmap cm, int len)
{
	register int	i;

	*num = 0;
	i = 0;
	while ((*str) && (len-- > 0) &&
		((i = ft_strnidx(cm.cmap, (int)(*str), (size_t)cm.base)) >= 0))
	{
		*num = (*num * (uintmax_t)cm.base) + (uintmax_t)(i);
		str++;
	}
	return (str);
}
