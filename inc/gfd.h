/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:28:22 by adelille          #+#    #+#             */
/*   Updated: 2022/01/29 11:57:13 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLD_H
# define FLD_H

//# include "libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# ifndef FLD_BUFFER
#  define FLD_BUFFER	280000
# elif FLD_BUFFER <= 0
#  define FLD_BUFFER	1
# endif

typedef struct s_file_data_chain
{
	char						*p;
	struct s_file_data_chain	*next;
}								t_gfdc;

typedef struct s_file_data
{
	t_gfdc	*data;
	size_t	n_line;
}			t_gfd;

bool	gfd(t_gfd *gfd, const int fd);
t_gfdc	*gfd_new(void);
bool	gfd_addback(t_gfdc **alst, t_gfdc *new);
t_gfdc	*gfd_last(t_gfdc *gfdc);
bool	gfd_clear(t_gfdc **gfdc);

#endif
