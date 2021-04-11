/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:28:58 by adelille          #+#    #+#             */
/*   Updated: 2021/04/11 19:33:29 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PARSE_H
# define LIBFT_PARSE_H

# include "libft.h"

typedef struct	s_scanf_convert
{
	int			flag;
	int			maxwidth;
	void		*arg;
}				t_sfc;

typedef struct	s_scanf_buffer
{
	int			arglen;
	int			padding;
	const char	*src;
	const char	*c;
	const char	*ref;
	va_list		ap;
	t_sfc		arg;
}				t_sfb;

#endif
