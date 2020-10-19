/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:56:19 by adelille          #+#    #+#             */
/*   Updated: 2020/10/19 16:56:26 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memset(void *s, int c, size_t len)
{
    size_t  i;

    if (!s)
        return (NULL);
    i = 0;
    while (i < len)
    {
        *(unsigned char*)(b + i) = (unsigned char)c;
        i++;
    }
    return (b);
}
