/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:04:32 by adelille          #+#    #+#             */
/*   Updated: 2024/07/18 19:02:34 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_pn(int nbr)
{
	ft_putnbr_fd(nbr, STDOUT_FILENO);
	return (ft_nbrlen(nbr));
}

ssize_t	ft_pner(int nbr)
{
	ft_putnbr_fd(nbr, STDERR_FILENO);
	return (ft_nbrlen(nbr));
}

ssize_t	ft_pnc(int nbr, const char *color)
{
	ssize_t	size;

	size = write(STDOUT_FILENO, color, ft_strlen(color));
	ft_putnbr_fd(nbr, STDOUT_FILENO);
	size += ft_nbrlen(nbr);
	size += write(STDOUT_FILENO, DEF, ft_strlen(DEF));
	return (size);
}

ssize_t	ft_pnerc(int nbr, const char *color)
{
	ssize_t	size;

	size = write(STDERR_FILENO, color, ft_strlen(color));
	ft_putnbr_fd(nbr, STDERR_FILENO);
	size += ft_nbrlen(nbr);
	size += write(STDERR_FILENO, DEF, ft_strlen(DEF));
	return (size);
}
