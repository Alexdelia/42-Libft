/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_with_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:46:33 by adelille          #+#    #+#             */
/*   Updated: 2021/04/11 19:52:07 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

const char	*ft_find_with_pointer(const char *format_to_find,
		const char *c, size_t *len)
{
	const char	*cpy;

	if (!format_to_find || !c)
		return (NULL);
	*len = 0;
	while (*format_to_find)
	{
		cpy = c;
		while (*cpy)
			if (*(cpy++) == *format_to_find)
				return (format_to_find);
		(*len) += 1;
		format_to_find++;
	}
	return (NULL);
}
