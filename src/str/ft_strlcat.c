/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:33:02 by adelille          #+#    #+#             */
/*   Updated: 2024/07/18 19:15:25 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_i;
	size_t	dst_i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	dst_i = dst_len;
	src_i = 0;
	if (dst_len < size - 1 && size > 0)
	{
		while (src[src_i] && dst_len + src_i < size - 1)
		{
			dst[dst_i] = src[src_i];
			dst_i++;
			src_i++;
		}
		dst[dst_i] = '\0';
	}
	if (dst_len >= size)
		dst_len = size;
	return (dst_len + src_len);
}
