/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfflag2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:22:07 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 16:27:10 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

const char	*ft_sfflag_z(const char *c, t_sfb *b)
{
	b->arg.flag |= SFF_SIZE_T;
	return (c + 1);
}

const char	*ft_sfflag_width(const char *c, t_sfb *b)
{
	c = ft_parse_digit(c, (t_ui *)&(b->arg.maxwidth));
	b->arg.flag |= SFF_MXW_SET;
	return (c);
}

const char	*ft_sfflag_nc(const char *c, t_sfb *b)
{
	b->arg.flag |= SFF_IGNORE;
	return (c + 1);
}
