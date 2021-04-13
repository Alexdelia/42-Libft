/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:28:58 by adelille          #+#    #+#             */
/*   Updated: 2021/04/11 19:54:38 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PARSE_H
# define LIBFT_PARSE_H

# include "libft.h"

typedef struct	s_sscanf_convert
{
	int			flag;
	int			maxwidth;
	void		*arg;
}				t_sfc;

typedef struct	s_sscanf_buffer
{
	int			arglen;
	int			padding;
	const char	*src;
	const char	*c;
	const char	*ref;
	va_list		ap;
	t_sfc		arg;
}				t_sfb;

int		ft_sscanf_loop(const char *format, t_sfb *b);
int		ft_find_with_pointer(const char *format_to_find,
				const char *c, size_t *len);

#endif
