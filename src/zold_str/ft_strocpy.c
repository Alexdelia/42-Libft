/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strocpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 12:56:24 by adelille          #+#    #+#             */
/*   Updated: 2023/11/19 14:19:20 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strocpy(char *dst, const char *src, const size_t size)
{
	uint64_t		*l_src;
	uint64_t		*l_dst;
	unsigned char	*c_src;
	unsigned char	*c_dst;
	size_t			n;

	n = size;
	l_src = (uint64_t *)src;
	l_dst = (uint64_t *)dst;
	while (n >= sizeof(uint64_t))
	{
		*l_dst++ = *l_src++;
		n -= sizeof(uint64_t);
	}
	if (n > 0)
	{
		c_src = (unsigned char *)l_src;
		c_dst = (unsigned char *)l_dst;
		while (n--)
			*c_dst++ = *c_src++;
	}
	return (size);
}
