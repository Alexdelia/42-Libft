/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:59:03 by adelille          #+#    #+#             */
/*   Updated: 2024/07/18 19:16:43 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ndst;
	const unsigned char	*nsrc;

	i = 0;
	ndst = dst;
	nsrc = src;
	while (i < n)
	{
		*(ndst + i) = *(nsrc + i);
		if (*(nsrc + i) == (unsigned char)c)
			return (ndst + i + 1);
		i++;
	}
	return (NULL);
}
