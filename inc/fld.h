/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fld.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:28:22 by adelille          #+#    #+#             */
/*   Updated: 2022/01/28 19:15:22 by adelille         ###   ########.fr       */
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
}								t_fldc;

typedef struct s_file_data
{
	t_fldc	*data;
	size_t	n_line;
}			t_fld;

bool	fld(t_fld *fld, int fd);
t_fldc	*fld_new(void);
bool	fld_addback(t_fldc **alst, t_fldc *new);
t_fldc	*fld_last(t_fldc *fldc);
bool	fld_clear(t_fldc **fldc);

#endif
