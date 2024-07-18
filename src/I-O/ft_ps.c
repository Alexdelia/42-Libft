/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 13:09:31 by adelille          #+#    #+#             */
/*   Updated: 2024/07/18 19:02:34 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_ps(const char *str)
{
	return (write(STDOUT_FILENO, str, ft_strlen(str)));
}

ssize_t	ft_psc(const char *str, const char *color)
{
	return (write(STDOUT_FILENO, color, ft_strlen(color))
		+ write(STDOUT_FILENO, str, ft_strlen(str))
		+ write(STDOUT_FILENO, DEF, ft_strlen(DEF)));
}

ssize_t	ft_pser(const char *str)
{
	return (write(STDERR_FILENO, str, ft_strlen(str)));
}

ssize_t	ft_pserc(const char *str, const char *color)
{
	return (write(STDERR_FILENO, color, ft_strlen(color))
		+ write(STDERR_FILENO, str, ft_strlen(str))
		+ write(STDERR_FILENO, DEF, ft_strlen(DEF)));
}
