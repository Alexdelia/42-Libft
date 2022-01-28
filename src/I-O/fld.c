/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:47:25 by adelille          #+#    #+#             */
/*   Updated: 2022/01/28 19:13:37 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fld.h"

static bool	fld_error(t_fld *fld, int fd)
{
	if (fd != 0)
		close(fd);
	return (fld_clear(&(fld->data)));
}

bool	fld(t_fld *fld, int fd)
{
	ssize_t	res;
	t_fldc	*current;

	fld->data = fld_new();
	current = fld->data;
	res = 1;
	while (res > 0)
	{
		current->p = (char *)malloc(sizeof(char) * FLD_BUFFER);
		if (!current->p)
			return (fld_error(fld, fd));
		res = read(fd, current->p, FLD_BUFFER);
		if (res < 0)
			return (fld_error(fld, fd));
		current->p[res] = '\0';
		if (!fld_addback(&fld->data, fld_new()))
			return (fld_error(fld, fd));
		current = current->next;
		fld->n_line++;
	}
	if (fd != 0)
		close(fd);
	return (true);
}
