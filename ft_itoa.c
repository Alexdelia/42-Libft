/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 02:22:35 by adelille          #+#    #+#             */
/*   Updated: 2020/11/07 02:39:18 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n);
{
	char	*str;
	int		neg;
	int		tmp;
	size_t	i;

	neg = 1;
	i = 0;
	if (n < 0)
	{
		n = -n;
		neg = -neg;
		i++;
	}
	tmp = n;
	while (tmp != 0)
	{
		tmp = (tmp / 10);
		i++;
	}
	if (!(str = ft_calloc(i + 1, sizeof(*str))))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (i > 0)
	{
		str[i] = '0' + (n % 10);
		n = (n / 10);
		i--;
	}
	if (neg == -1)
		str[0] == '-';
	return (str);
}
