/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfbuftoarg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:45:19 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 16:57:58 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void			ft_bufskip(const char **str, int len, t_cmap cm)
{
	const char	*c;

	c = *str;
	if ((*c == '+') || (*c == '-'))
	{
		c++;
		len--;
	}
	while (*c && (len-- > 0) &&
		(ft_strnidx(cm.cmap, (int)*c, (size_t)cm.base) >= 0))
		++c;
	*str = c;
}

intmax_t		ft_buftoj(const char **str, int len, t_cmap cm)
{
	uintmax_t		ret;
	char			sig;

	sig = (**str == '-') ? 0 : 1;
	if (**str == '+' || **str == '-')
	{
		(*str)++;
		len--;
	}
	*str = ft_parsej_cmap(*str, &ret, cm, len);
	return ((intmax_t)(sig ? ret : (~(uintmax_t)0) - (ret - 1)));
}

long			ft_buftol(const char **str, int len, t_cmap cm)
{
	unsigned long	ret;
	char			sig;

	sig = (**str == '-') ? 0 : 1;
	if (**str == '+' || **str == '-')
	{
		(*str)++;
		len--;
	}
	*str = ft_parse_cmap(*str, &ret, cm, len);
	return ((long)(sig ? ret : 0xFFFFFFFFFFFFFFFFul - (ret - 1)));
}

int				ft_buftoi(const char **str, int len, t_cmap cm)
{
	unsigned long	ret;
	char			sig;

	sig = (**str == '-') ? 0 : 1;
	if (**str == '+' || **str == '-')
	{
		(*str)++;
		len--;
	}
	*str = ft_parse_cmap(*str, &ret, cm, len);
	return ((int)(sig ? ret : 0xFFFFFFFFu - (unsigned int)(ret - 1)));
}

int				ft_sfbuftoarg(t_sfb *b, t_sfc *arg, t_cmap cm)
{
	const int	len = arg->maxwidth;

	if (arg->flag & SFF_IGNORE)
		ft_bufskip(&(b->c), len, cm);
	else if (arg->flag & SFF_INTMAX)
		*(intmax_t *)(arg->arg) = ft_buftoj(&(b->c), len, cm);
	else if (arg->flag & SFF_SIZE_T)
		*(ssize_t *)(arg->arg) = (ssize_t)ft_buftoj(&(b->c), len, cm);
	else if (arg->flag & SFF_LONG_LONG)
		*(long long *)(arg->arg) = (long long)ft_buftoj(&(b->c), len, cm);
	else if (arg->flag & (SFF_LONG | SFF_CAPITAL))
		*(long *)(arg->arg) = ft_buftol(&(b->c), len, cm);
	else if (arg->flag & SFF_SHORT)
		*(short *)(arg->arg) = (short)ft_buftoi(&(b->c), len, cm);
	else if (arg->flag & SFF_SHORT_SHORT)
		*(char *)(arg->arg) = (char)ft_buftoi(&(b->c), len, cm);
	else
		*(int *)(arg->arg) = ft_buftoi(&(b->c), len, cm);
	return (0);
}
