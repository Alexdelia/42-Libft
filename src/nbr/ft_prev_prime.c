/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prev_prime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:10:35 by adelille          #+#    #+#             */
/*   Updated: 2023/11/19 14:19:21 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_prev_prime(int n)
{
	if (n <= 2)
		return (INT_MAX);
	if (n % 2 == 0)
		n--;
	else
		n -= 2;
	while (ft_is_prime(n) == false)
		n -= 2;
	return (n);
}

unsigned long	ft_prev_prime_ul(unsigned long n)
{
	if (n <= 2)
		return (0);
	if (n % 2 == 0)
		n--;
	else
		n -= 2;
	while (ft_is_prime(n) == false)
		n -= 2;
	return (n);
}
