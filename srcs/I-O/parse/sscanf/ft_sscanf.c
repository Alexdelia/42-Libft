/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:16:25 by adelille          #+#    #+#             */
/*   Updated: 2021/04/11 19:41:03 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_init_sscanf(t_sfb *buffer, const char *str, const char *format)
{
	buffer->arglen = -1;
	buffer->src = str;
	buffer->c = str;
	buffer->red = format;
}

int			ft_sscanf(const char *str, const char *format, ...)
{
	t_sfb	buffer;

	if (!format)
		return (-1);
	ft_init_sscanf(&buffer, str, format);
	va_start(buffer.ap, format);
	ft_sscanf_loop(format, &buffer);
	va_end(buffer.ap);
	return (buffer.arglen);
}
