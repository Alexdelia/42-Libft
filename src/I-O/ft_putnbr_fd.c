/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 02:56:13 by adelille          #+#    #+#             */
/*   Updated: 2023/11/19 14:19:19 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str[13];
	int		is_neg;
	int		len;

	is_neg = (n < 0);
	ft_bzero(str, 13);
	if (n == 0)
		str[0] = '0';
	len = 0;
	while (n != 0)
	{
		str[len++] = '0' + ft_abs(n % 10);
		n = (n / 10);
	}
	if (is_neg)
		str[len] = '-';
	else if (len > 0)
		len--;
	while (len >= 0)
		write(fd, &str[len--], 1);
}
