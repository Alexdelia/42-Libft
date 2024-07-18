/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:47:31 by adelille          #+#    #+#             */
/*   Updated: 2024/07/18 19:31:38 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *s, const char *match, size_t len)
{
	size_t	y;
	size_t	x;

	if (!s || !match || !*match)
		return ((char *)s);
	y = 0;
	while (y < len && s[y])
	{
		x = 0;
		while (y + x < len && s[y + x] && match[x] && s[y + x] == match[x])
			x++;
		if (!match[x])
			return ((char *)(s + y));
		y++;
	}
	return (NULL);
}
