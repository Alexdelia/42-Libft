/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 13:09:31 by adelille          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/02/26 13:38:31 by adelille         ###   ########.fr       */
=======
/*   Updated: 2021/02/28 18:40:18 by adelille         ###   ########.fr       */
>>>>>>> 3f0486b87fc3c550cf6df121a2bdf09ba197e281
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ps(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}
