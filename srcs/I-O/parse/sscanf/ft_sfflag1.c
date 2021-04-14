/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfflag1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:22:39 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 16:22:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

const char	*ft_sfflag_j(const char *c, t_sfb *b)
{
	b->arg.flag |= SFF_INTMAX;
	return (c + 1);
}

const char	*ft_sfflag_h(const char *c, t_sfb *b)
{
	if (c[1] == 'h')
	{
		b->arg.flag |= SFF_SHORT_SHORT;
		++c;
	}
	else
		b->arg.flag |= SFF_SHORT;
	return (c + 1);
}

const char	*ft_sfflag_l(const char *c, t_sfb *b)
{
	if (c[1] == 'l')
	{
		b->arg.flag |= SFF_LONG_LONG;
		++c;
	}
	else if (*c == 'L')
		b->arg.flag |= SFF_LONG_LONG;
	else
		b->arg.flag |= SFF_LONG;
	return (c + 1);
}
