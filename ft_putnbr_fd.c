/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 02:56:13 by adelille          #+#    #+#             */
/*   Updated: 2020/11/16 14:44:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	main_loop(int i, int n, int fd)
{
	char	c;

	while (i > 0)
	{
		c = '0' + (n % 10);
		n = (n / 10);
		i--;
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		tmp;
	size_t	i;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	i = 0;
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
		i++;
	}
	tmp = n;
	while (tmp != 0)
	{
		tmp = (tmp / 10);
		i++;
	}
	main_loop(i, n, fd);
}
