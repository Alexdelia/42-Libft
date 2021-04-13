/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:41:15 by adelille          #+#    #+#             */
/*   Updated: 2021/04/11 20:00:46 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	ft_valid_format(const char *format, t_sfb *b, size_t *len)
{
	const char	*c;

	while (*len)
	{
		c = b->c + 1;
		if ((*format == ' ')
				&& ((c = ft_strpskp(b->c, FT_WHITESPACE)) == b->c))
			return (0);
		else if (*format != *(b->c))
			return (0);
		b->c = c;
		++format;
		--(*len);
	}
	return (1);
}

int			ft_sscanf_loop(const char *format, t_sfb *b)
{
	const char	*c;
	size_t		len;

	while ((format) && (c = ft_find_with_pointer(format, "%", &len)))
	{
		if (!ft_valid_format(format, b, &len))
			break ;
		if (b->arglen < 0)
			b->arglen = 0;
		format = ft_sscanf_parse(c + 1, format);
	}
	return (0);
}
