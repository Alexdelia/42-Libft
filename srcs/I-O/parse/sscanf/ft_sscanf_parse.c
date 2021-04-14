/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:28:31 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 17:55:55 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void			ft_init_sscanf_arg(t_sfc *arg)
{
	arg->arg = NULL;
	arg->maxwidth = (int)(~FT_SM_I);
	arg->flag = SFF_NONE;
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
	if (ft_isupper_int((int)(*c)))
		b->arg.flag |= SFF_CAPITAL;
	ret = g_sf_flag_tab[i].convert(&c, b, &(b->arg));
	if (ret < 0)
		return (NULL);
	b->arglen += ret;
	return (c);
}
