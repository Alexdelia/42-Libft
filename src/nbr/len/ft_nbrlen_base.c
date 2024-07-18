/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:07:52 by adelille          #+#    #+#             */
/*   Updated: 2024/07/18 20:12:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline size_t	ft_nbrlen_base(ssize_t n, size_t base)
{
	if (n < 0)
		return (1 + ft_unbrlen_base((size_t)(-n), base));
	return (ft_unbrlen_base((size_t)n, base));
}
