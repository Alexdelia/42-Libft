/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_prime_1_opti.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:10:35 by adelille          #+#    #+#             */
/*   Updated: 2021/11/04 13:57:04 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static bool ft_is_prime(int n)
{
	int	div;

	if (n == 2 || n == 3)
		return (true);
	if (n <= 1 || n % 2 == 0 || n % 3 == 0)
		return (false);
	div = 5;
	while (div * div <= n)
	{
		if (n % div == 0)
			return (false);
		div += 6;
	}
	return (true);
}

int	ft_next_prime(int n)
{
	if (n <= 1)
		return (2);
	if (n % 2 == 0)
		n++;
	else
		n += 2;
	while (ft_is_prime(n) == false)
		n += 2;
	return (n);
}

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
