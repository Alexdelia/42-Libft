/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:02:43 by adelille          #+#    #+#             */
/*   Updated: 2021/02/26 07:53:45 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int			i;
	char		*ndest;
	const char	*nsrc;

	if (!dest && !src)
		return (NULL);
	ndest = dest;
	nsrc = src;
	if (ndest > nsrc)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(ndest + i) = *(nsrc + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(ndest + i) = *(nsrc + i);
			i++;
		}
	}
	return (ndest);
}
