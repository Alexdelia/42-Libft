/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:12:27 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 17:13:00 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

const char	*ft_parseld(const char *str, long double *num, t_cmap cm, int len)
{
	register int	i;
	long double		d;

	*num = (long double)0.0;
	i = 0;
	while ((*str) && (len-- > 0) &&
		((i = ft_strnidx(cm.cmap, (int)(*str), (size_t)cm.base)) >= 0))
	{
		*num = (*num * (long double)cm.base) + (long double)(i);
		str++;
	}
	if ((*str == '.') && (len-- > 0))
	{
		str++;
		d = (long double)cm.base;
		while ((*str) && (len-- > 0) &&
			((i = ft_strnidx(cm.cmap, (int)(*str), (size_t)cm.base)) >= 0))
		{
			*num += (long double)(i) / d;
			d *= (long double)cm.base;
			str++;
		}
	}
	return (str);
}
