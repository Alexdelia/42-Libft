/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 13:09:31 by adelille          #+#    #+#             */
/*   Updated: 2021/11/18 16:12:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_ps(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return(write(STDOUT, str, i));
}

int	ft_psc(char *str, char *color)
{
	return (write(STDOUT, color, ft_strlen(color))
			+ write(STDOUT, str, ft_strlen(str))
			+ write(STDOUT, DEF, ft_strlen(DEF)));
}

int	ft_pser(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (write(STDERR, str, i));
}

int	ft_pserc(char *str, char *color)
{
	return (write(STDERR, color, ft_strlen(color))
			+ write(STDERR, str, ft_strlen(str))
			+ write(STDERR, DEF, ft_strlen(DEF)));
}
