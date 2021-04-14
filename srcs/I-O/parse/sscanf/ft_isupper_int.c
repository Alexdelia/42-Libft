/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:08:38 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 16:09:48 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		ft_isupper_int(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
