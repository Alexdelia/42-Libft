/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:00:07 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 16:01:45 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

const char	*ft_parse_digit(const char *str, unsigned int *num)
{
	*num = 0;
	while (ft_isdigit_int((int)(*str)))
		*num = ((*num * 10) + (unsigned int)(*(str++) - '0'));
	return (str);
}
