/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfbuftofarg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:04:49 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 17:16:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_bufskipf(const char **str, int len, t_cmap cm)
{
	const char	*c;

	c = *str;
	if ((*c == '+') || (*c == '-'))
	{
		(c)++;
		len--;
	}
	while ((*c) && (len-- > 0) &&
		(ft_strnidx(cm.cmap, (int)*c, (size_t)cm.base) >= 0))
		++c;
	if ((*c == '.') && (len-- > 0))
	{
		++c;
		while (*c && (len-- > 0) &&
			(ft_strnidx(cm.cmap, (int)*c, (size_t)cm.base) >= 0))
			++c;
	}
	*str = c;
}

int		ft_sfbuftofarg(t_sfb *b, t_sfc *arg, t_cmap cm)
{
	const int	len = arg->maxwidth;

	if (arg->flag & SFF_IGNORE)
		ft_bufskipf(&(b->c), len, cm);
	else if (arg->flag & SFF_LONG_LONG)
		*(long double *)(arg->arg) = ft_buftold(&(b->c), len, cm);
	else if (arg->flag & (SFF_LONG | SFF_CAPITAL))
		*(double *)(arg->arg) = ft_buftod(&(b->c), len, cm);
	else
		*(float *)(arg->arg) = ft_buftof(&(b->c), len, cm);
	return (0);
}
