/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:53:20 by adelille          #+#    #+#             */
/*   Updated: 2024/07/18 19:16:43 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*ndst;
	const char	*nsrc;

	ndst = dst;
	nsrc = src;
	if (!ndst && !nsrc)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(ndst + i) = *(nsrc + i);
		i++;
	}
	return (ndst);
}
