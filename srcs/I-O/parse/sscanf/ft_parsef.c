/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsef.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:09:55 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 17:10:30 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

const char	*ft_parsef(const char *str, double *num, t_cmap cm, int len)
{
	register int	i;
	double			d;

	*num = 0.0;
	i = 0;
	while ((*str) && (len-- > 0) &&
		((i = ft_strnidx(cm.cmap, (int)(*str), (size_t)cm.base)) >= 0))
	{
		*num = (*num * (double)cm.base) + (double)(i);
		str++;
	}
	if ((*str == '.') && (len-- > 0))
	{
		str++;
		d = (double)cm.base;
		while ((*str) && (len-- > 0) &&
			((i = ft_strnidx(cm.cmap, (int)(*str), (size_t)cm.base)) >= 0))
		{
			*num += (double)(i) / d;
			d *= (double)cm.base;
			str++;
		}
	}
	return (str);
}
