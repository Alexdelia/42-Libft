/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:47:25 by adelille          #+#    #+#             */
/*   Updated: 2022/01/29 11:40:58 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/gfd.h"

static bool	gfd_error(t_gfd *gfd, int fd)
{
	if (fd != 0)
		close(fd);
	return (gfd_clear(&(gfd->data)));
}

bool	gfd(t_gfd *gfd, int fd)
{
	ssize_t	res;
	t_gfdc	*current;

	gfd->data = gfd_new();
	current = gfd->data;
	res = 1;
	while (res > 0)
	{
		current->p = (char *)malloc(sizeof(char) * FLD_BUFFER);
		if (!current->p)
			return (gfd_error(gfd, fd));
		res = read(fd, current->p, FLD_BUFFER);
		if (res < 0)
			return (gfd_error(gfd, fd));
		current->p[res] = '\0';
		if (!gfd_addback(&gfd->data, gfd_new()))
			return (gfd_error(gfd, fd));
		current = current->next;
		gfd->n_line++;
	}
	if (fd != 0)
		close(fd);
	return (true);
}
