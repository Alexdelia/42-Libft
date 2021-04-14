/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfconv3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:31:20 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 17:35:17 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	*ft_sf_strncpy(char *dst, const char *src, size_t n)
{
	char	*dit;

	dit = dst;
	if (!n)
		return (dst);
	while (n--)
	{
		*(dit++) = *src;
		if (*src)
			src++;
	}
	return (dst);
}

static int	ft_sf_strcspn(const char *s, const char *stopset)
{
	int	i;

	i = 0;
	while ((*s) && !(ft_str_point_chr(stopset, (int)(*(s++)))))
		++i;
	return (i);
}

int			ft_sfconv_s(const char **c, t_sfb *b, t_sfc *arg)
{
	char			*buf;
	int				len;

	b->c = ft_str_point_skip(b->c, FT_WHITESPACE);
	len = ft_sf_strcspn(b->c, FT_WHITESPACE);
	if (!len)
		return (-1);
	len = (len > arg->maxwidth) ? arg->maxwidth : len;
	if (!(arg->flag & SFF_IGNORE))
	{
		buf = va_arg(b->ap, char *);
		ft_sf_strncpy(buf, b->c, (size_t)len);
		buf[len] = '\0';
	}
	b->c += len;
	(*c)++;
	return ((arg->flag & SFF_IGNORE) ? 0 : 1);
}

static void	*ft_sf_memcpy(void *dst, const void *src, size_t n)
{
	register size_t		aln;

	aln = n % sizeof(long);
	while (aln-- && n--)
		((char *)dst)[n] = ((const char *)src)[n];
	aln = n / sizeof(long);
	while (aln--)
		((unsigned long *)dst)[aln] = ((const unsigned long *)src)[aln];
	return (dst);
}

int			ft_sfconv_c(const char **c, t_sfb *b, t_sfc *arg)
{
	int				len;

	len = (arg->flag & SFF_MXW_SET) ? arg->maxwidth : 1;
	if (ft_strnidx(b->c, 0, (size_t)len) >= 0)
		return (-1);
	if (!(arg->flag & SFF_IGNORE))
		ft_sf_memcpy(va_arg(b->ap, char *), b->c, (size_t)len);
	b->c += len;
	(*c)++;
	return ((arg->flag & SFF_IGNORE) ? 0 : 1);
}
