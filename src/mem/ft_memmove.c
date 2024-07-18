/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:02:43 by adelille          #+#    #+#             */
/*   Updated: 2024/07/18 19:16:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memmove_end(char *dst, const char *src, size_t n)
{
	ssize_t	i;

	if (dst > src)
	{
		i = (ssize_t)n - 1;
		while (i >= 0)
		{
			*(dst + i) = *(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (ssize_t)n)
		{
			*(dst + i) = *(src + i);
			i++;
		}
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*ndst;
	const char	*nsrc;

	if (!dst && !src)
		return (NULL);
	ndst = dst;
	nsrc = src;
	return (ft_memmove_end(ndst, nsrc, n));
}
