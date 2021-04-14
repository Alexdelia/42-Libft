/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:28:31 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 16:08:29 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void			ft_init_sscanf_arg(t_sfb *arg)
{
	arg->arg = NULL;
	arg->maxwidth = (int)(~FT_SM_I);
	arg->flag = SFF_NONE;
}

static const char	*ft_sfflag_width(const char *c, t_sfb *b)
{
	c = ft_parse_digit(c, (t_ui *)&(b->arg.maxwidth));
	b->arg.flag |= SFF_MXW_SET;
	return (c);
}

const char			*ft_sscanf_parse(t_sfb *b, const char *format)
{
	const char	*c;
	int			i;
	int			ret;

	i = 0;
	c = format;
	ft_init_sscanf_arg(&(b->arg));
	while ((*c) && ((i = ft_stridx(SF_TYPE_STR, (int)(*c))) == -1))
	{
		if ((i = ft_stridx(SF_FLAG_STR, (int)(*c))) >= 0)
			c = g_sf_flag_tab[i].flag(c, b);
		else if (ft_isdigit_int((int)(*c)))
			c = ft_sfflag_width(c, b);
		else
			break ;
	}
	if ((!*c) || (i == -1))
		return (NULL);
	if (ft_isupper((int)(*c)))
		b->arg.flag |= SFF_CAPITAL;
	ret = g_sf_flag_tab[i].convert(&c, b, &(b->arg));
	if (ret < 0)
		return (NULL);
	b->arglen += ret;
	return (c);
}
