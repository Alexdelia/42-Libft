/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:08:00 by adelille          #+#    #+#             */
/*   Updated: 2024/07/18 20:08:02 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// will crash if base is 0 which is not protected for optimization reasons
// it is the responsibility of the dev to use ft_check_base() != 0 beforehand
size_t	ft_unbrlen_base(size_t n, size_t base)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}
