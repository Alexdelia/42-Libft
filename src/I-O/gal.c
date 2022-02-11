/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:50:56 by adelille          #+#    #+#             */
/*   Updated: 2022/02/11 16:21:57 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static char	*gal_error(const int fd, char *output)
{
	if (fd != 0)
		close(fd);
	if (output)
		free(output);
	return (NULL);
}

static char	*gal_big(const int fd, char *output, size_t *size)
{
	ssize_t	res;
	size_t	capacity;
	size_t	mult;

	mult = 1;
	while (res > 0)
	{
		output = ft_str_extend(output, *size, capacity);
		res = read(fd, &output[*size], capacity); // capacity is not right
		if (res < 0)
			return (gal_error(fd, output));
		if (res == 0)
			break ;
		output[res] = '\0';
		*size += res;
		++mult;
		capacity *= 2;
	}
	if (fd != 0)
		close(fd);
	return (output);
}

char	*gal(const int fd, size_t *size)
{
	char	*output;
	ssize_t	res;

	*size = 0;
	output = (char *)malloc(sizeof(char) * GAL_INIT_BUFFER + 1);
	if (!output)
		return (gal_error(fd, output));
	res = read(fd, output, GAL_INIT_BUFFER);
	if (res < 0)
		return (gal_error(fd, output));
	output[res] = '\0';
	*size += res;
	if (res == 0)
		return (output);
	return (gal_big(fd, output, size));
}
