/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfconv2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:28:15 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 18:08:45 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	ft_valid_num(char c, const char *s, int len)
{
	if ((len > 1) && ((*s == '+') || (*s == '-')))
		++s;
	if (((c == 'x') && !ft_strchr(FT_DIGIT_L, (int)(*s))) ||
		((c == 'X') && !ft_strchr(FT_DIGIT, (int)(*s))) ||
		(((c == 'o') || (c == 'O')) && !ft_strchr(FT_DIGIT_L, (int)(*s))) ||
		!ft_strchr(FT_DECIMAL_DIGIT, (int)*s))
		return (0);
	return (1);
}

int			ft_sfconv_u(const char **c, t_sfb *b, t_sfc *arg)
{
	b->c = ft_str_point_skip(b->c, FT_WHITESPACE);
	if (!ft_valid_num(**c, b->c, arg->maxwidth))
		return (-1);
	else if (!(arg->flag & SFF_IGNORE))
		arg->arg = va_arg(b->ap, void *);
	if ((**c == 'o') || (**c == 'O'))
		ft_sfbuftouarg(b, arg, g_cmapup[6]);
	if ((**c == 'x') || (**c == 'X'))
	{
		arg->flag &= ~SFF_CAPITAL;
		if ((b->c[0] == 0) && (b->c[1] == **c) && (arg->maxwidth > 1))
		{
			b->c += 2;
			arg->maxwidth -= 2;
		}
		ft_sfbuftouarg(b, arg, (**c == 'x') ? g_cmaplow[14] : g_cmapup[14]);
	}
	else
		ft_sfbuftouarg(b, arg, g_cmapup[8]);
	(*c)++;
	return ((arg->flag & SFF_IGNORE) ? 0 : 1);
}

int			ft_sfconv_n(const char **c, t_sfb *b, t_sfc *arg)
{
	int			*iptr;

	if (**c == '%')
	{
		(*c)++;
		b->c = ft_str_point_skip(b->c, FT_WHITESPACE);
		return ((*(b->c++) == '%') ? 0 : -1);
	}
	else if ((**c == 'n') || (**c == 'N'))
	{
		iptr = va_arg(b->ap, int *);
		arg->arg = iptr;
		if (**c == 'n')
			*iptr = (int)(b->c - b->src);
		else
			*iptr = b->arglen;
		(*c)++;
	}
	return (0);
}
