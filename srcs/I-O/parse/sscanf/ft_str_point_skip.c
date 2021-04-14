/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_point_skip.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:23:42 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 17:21:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char		*ft_str_point_chr(const char *str, int c)
{
	while (*str)
	{
		if (*(str++) == (char)c)
			return ((char *)(unsigned long)(--str));
	}
	return (c ? NULL : (char *)(unsigned long)str);
}

char		*ft_str_point_skip(const char *str, const char *skipset)
{
	while (*str)
	{
		if (!ft_str_point_chr(skipset, int(*(str++))))
			return ((char *)(unsigned long)(--str));
	}
	return ((char *)(unsigned long)str);
}
