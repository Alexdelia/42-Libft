/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:02:43 by adelille          #+#    #+#             */
/*   Updated: 2020/11/16 14:24:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int i;

	if (!dest || !src)
		return (NULL);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char*)(dest + i) = *(char*)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char*)(dest + i) = *(char*)(src + i);
			i++;
		}
	}
	return (dest);
}
