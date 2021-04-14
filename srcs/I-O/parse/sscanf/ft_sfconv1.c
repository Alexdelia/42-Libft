/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfconv1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:27:27 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 17:30:01 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	ft_valid_num(const char *str, int len)
{
	if ((len > 1) && ((*str == '+') || (*str == '-')))
		++str;
	if (ft_str_point_chr(FT_DECIMAL_DIGIT, (int)*str))
		return (1);
	return (0);
}

int			ft_sfconv_d(const char **c, t_sfb *b, t_sfc *arg)
{
	b->c = ft_str_point_skip(b->c, FT_WHITESPACE);
	if (!ft_valid_num(b->c, arg->maxwidth))
		return (-1);
	if (!(arg->flag & SFF_IGNORE))
		arg->arg = va_arg(b->ap, void *);
	ft_sfbuftoarg(b, arg, g_cmapup[8]);
	(*c)++;
	return ((arg->flag & SFF_IGNORE) ? 0 : 1);
}

int			ft_sfconv_i(const char **c, t_sfb *b, t_sfc *arg)
{
	b->c = ft_str_point_skip(b->c, FT_WHITESPACE);
	if (!ft_valid_num(b->c, arg->maxwidth))
		return (-1);
	if (!(arg->flag & SFF_IGNORE))
		arg->arg = va_arg(b->ap, void *);
	ft_sfbuftoarg(b, arg, g_cmapup[8]);
	(*c)++;
	return ((arg->flag & SFF_IGNORE) ? 0 : 1);
}

int			ft_sfconv_f(const char **c, t_sfb *b, t_sfc *arg)
{
	b->c = ft_strpskp(b->c, FT_WHITESPACE);
	if (!ft_valid_num(b->c, arg->maxwidth))
		return (-1);
	if (!(arg->flag & SFF_IGNORE))
		arg->arg = va_arg(b->ap, void *);
	ft_sfbuftofarg(b, arg, g_cmapup[8]);
	(*c)++;
	return ((arg->flag & SFF_IGNORE) ? 0 : 1);
}
