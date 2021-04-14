/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfbuftouarg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:01:47 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 17:04:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

unsigned int	ft_buftoui(const char **str, int len, t_cmap cm)
{
	unsigned long	ret;

	*str = ft_parse_cmap(*str, &ret, cm, len);
	return ((unsigned int)ret);
}

unsigned long	ft_buftoul(const char **str, int len, t_cmap cm)
{
	unsigned long	ret;

	*str = ft_parse_cmap(*str, &ret, cm, len);
	return (ret);
}

uintmax_t		ft_buftouj(const char **str, int len, t_cmap cm)
{
	uintmax_t		ret;

	*str = ft_parsej_cmap(*str, &ret, cm, len);
	return (ret);
}

int				ft_sfbuftouarg(t_sfb *b, t_sfc *arg, t_cmap cm)
{
	const int	len = arg->maxwidth;

	if (arg->flag & SFF_IGNORE)
		ft_bufskip(&(b->c), len, cm);
	else if (arg->flag & SFF_INTMAX)
		*(uintmax_t *)(arg->arg) = ft_buftouj(&(b->c), len, cm);
	else if (arg->flag & SFF_SIZE_T)
		*(size_t *)(arg->arg) = (size_t)ft_buftouj(&(b->c), len, cm);
	else if (arg->flag & SFF_LONG_LONG)
		*(unsigned long long *)(arg->arg) = (unsigned long long)ft_buftouj(
			&(b->c), len, cm);
	else if (arg->flag & (SFF_LONG | SFF_CAPITAL))
		*(t_ul *)(arg->arg) = ft_buftoul(&(b->c), len, cm);
	else if (arg->flag & SFF_SHORT)
		*(t_us *)(arg->arg) = (t_us)ft_buftoui(&(b->c), len, cm);
	else if (arg->flag & SFF_SHORT_SHORT)
		*(t_uc *)(arg->arg) = (t_uc)ft_buftoui(&(b->c), len, cm);
	else
		*(t_ui *)(arg->arg) = ft_buftoui(&(b->c), len, cm);
	return (0);
}
