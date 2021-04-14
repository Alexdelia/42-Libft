/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:28:58 by adelille          #+#    #+#             */
/*   Updated: 2021/04/14 18:07:59 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PARSE_H
# define LIBFT_PARSE_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

# define FT_DIGIT			"0123456789ABCDEF"
# define FT_DIGIT_L			"0123456789abcdef"
# define FT_DECIMAL_DIGIT	"0123456789"
# define FT_DECIMAL_C		"+-0123456789"
# define FT_OCTAL_C			"01234567"
# define FT_HEXA_C			"+-0123456789ABCDEF"
# define FT_HEXA_C_L		"+-0123456789abcdef"

# define FT_WHITESPACE		" \t\n\r\v\f"

# define FT_MX_FLOATLEN		310

# define FT_SM_C	0x80u
# define FT_SM_S	0x8000u
# define FT_SM_I	0x80000000u
# define FT_SM_L	0x8000000000000000ul

# define FT_F_EXP	0x7f800000u
# define FT_F_MAN	0x007fffffu

# define FT_D_EXP	0x7ff0000000000000ul
# define FT_D_MAN	0x000ffffffffffffful

# define SF_TYPE_STR	"idfxXusc%onN"
# define SF_FLAG_STR	"*hljz"

typedef unsigned int	t_idx;
typedef unsigned char	t_uc;
typedef unsigned short	t_us;
typedef unsigned int	t_ui;
typedef unsigned long	t_ul;
typedef unsigned long	t_np;

typedef const struct    s_char_map
{
    t_ui                base;
    int                    padding;
    const char            *cmap;
}                        t_cmap;

static const char		g_digitupmap[] = FT_DIGIT;
static const char		g_digitlowmap[] = FT_DIGIT_L;
static t_cmap			g_cmapup[] = {
	(t_cmap){2, 0, g_digitupmap},
	(t_cmap){3, 0, g_digitupmap},
	(t_cmap){4, 0, g_digitupmap},
	(t_cmap){5, 0, g_digitupmap},
	(t_cmap){6, 0, g_digitupmap},
	(t_cmap){7, 0, g_digitupmap},
	(t_cmap){8, 0, g_digitupmap},
	(t_cmap){9, 0, g_digitupmap},
	(t_cmap){10, 0, g_digitupmap},
	(t_cmap){11, 0, g_digitupmap},
	(t_cmap){12, 0, g_digitupmap},
	(t_cmap){13, 0, g_digitupmap},
	(t_cmap){14, 0, g_digitupmap},
	(t_cmap){15, 0, g_digitupmap},
	(t_cmap){16, 0, g_digitupmap},
};
static t_cmap			g_cmaplow[] = {
	(t_cmap){2, 0, g_digitlowmap},
	(t_cmap){3, 0, g_digitlowmap},
	(t_cmap){4, 0, g_digitlowmap},
	(t_cmap){5, 0, g_digitlowmap},
	(t_cmap){6, 0, g_digitlowmap},
	(t_cmap){7, 0, g_digitlowmap},
	(t_cmap){8, 0, g_digitlowmap},
	(t_cmap){9, 0, g_digitlowmap},
	(t_cmap){10, 0, g_digitlowmap},
	(t_cmap){11, 0, g_digitlowmap},
	(t_cmap){12, 0, g_digitlowmap},
	(t_cmap){13, 0, g_digitlowmap},
	(t_cmap){14, 0, g_digitlowmap},
	(t_cmap){15, 0, g_digitlowmap},
	(t_cmap){16, 0, g_digitlowmap},
};

enum			e_sf_flag
{
	SFF_NONE = 0,
	SFF_IGNORE = 1,
	SFF_SHORT_SHORT = 1 << 10,
	SFF_SHORT = 1 << 11,
	SFF_LONG = 1 << 12,
	SFF_LONG_LONG = 1 << 13,
	SFF_INTMAX = 1 << 14,
	SFF_SIZE_T = 1 << 15,
	SFF_CAPITAL = 1 << 16,
	SFF_MXW_SET = 1 << 18,
	SFF_END = (int)(1u << 30)
};

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

typedef struct	s_sscanf_cftab
{
	const char	*(*flag)(const char *, t_sfb *);
	int			(*convert)(const char **, t_sfb*, t_sfc*);
}				t_sftab;

typedef struct	s_key_func
{
	const char	*key;
	int			(*func)(const char *, const char *, void *);
}				t_kf;

int				ft_sscanf_loop(const char *format, t_sfb *b);
const char		*ft_sscanf_parse(t_sfb *b, const char *format);
const char		*ft_find_with_pointer(const char *format_to_find,
					const char *c, size_t *len);
const char		*ft_parse_digit(const char *str, unsigned int *num);
const char		*ft_parsej_cmap(const char *str,
					uintmax_t *num, t_cmap cm, int len);
const char		*ft_parse_cmap(const char *str,
					unsigned long *num, t_cmap cm, int len);
const char		*ft_parsef(const char *str,
					double *num, t_cmap cm, int len);
const char		*ft_parseld(const char *str,
					long double *num, t_cmap cm, int len);

int				ft_sfbuftoarg(t_sfb *b, t_sfc *arg, t_cmap cm);
int				ft_sfbuftofarg(t_sfb *b, t_sfc *arg, t_cmap cm);
int				ft_sfbuftouarg(t_sfb *b, t_sfc *arg, t_cmap cm);


void			ft_bufskip(const char **str, int len, t_cmap cm);
int				ft_buftoi(const char **str, int len, t_cmap cm);
long			ft_buftol(const char **str, int len, t_cmap cm);
intmax_t		ft_buftoj(const char **str, int len, t_cmap cm);
unsigned int	ft_buftoui(const char **str, int len, t_cmap cm);
unsigned long	ft_buftoul(const char **str, int len, t_cmap cm);
uintmax_t		ft_buftouj(const char **str, int len, t_cmap cm);
float			ft_buftof(const char **str, int len, t_cmap cm);
double			ft_buftod(const char **str, int len, t_cmap cm);
long double		ft_buftold(const char **str, int len, t_cmap cm);

const char		*ft_sfflag_j(const char *c, t_sfb *b);
const char		*ft_sfflag_h(const char *c, t_sfb *b);
const char		*ft_sfflag_l(const char *c, t_sfb *b);
const char		*ft_sfflag_z(const char *c, t_sfb *b);
const char		*ft_sfflag_width(const char *c, t_sfb *b);
const char		*ft_sfflag_nc(const char *c, t_sfb *b);

int				ft_sfconv_d(const char **c, t_sfb *b, t_sfc *arg);
int				ft_sfconv_i(const char **c, t_sfb *b, t_sfc *arg);
int				ft_sfconv_u(const char **c, t_sfb *b, t_sfc *arg);
int				ft_sfconv_f(const char **c, t_sfb *b, t_sfc *arg);
int				ft_sfconv_s(const char **c, t_sfb *b, t_sfc *arg);
int				ft_sfconv_c(const char **c, t_sfb *b, t_sfc *arg);
int				ft_sfconv_n(const char **c, t_sfb *b, t_sfc *arg);

int				ft_stridx(const char *str, int c);
int				ft_strnidx(const char *str, int c, size_t n);
int				ft_isdigit_int(int c);
int				ft_isupper_int(int c);
char			*ft_str_point_chr(const char *str, int c);
char			*ft_str_point_skip(const char *str, const char *skipset);

const static t_sftab	g_sf_flag_tab[] = {
	(t_sftab){&ft_sfflag_nc, &ft_sfconv_i},
	(t_sftab){&ft_sfflag_h, &ft_sfconv_d},
	(t_sftab){&ft_sfflag_l, &ft_sfconv_f},
	(t_sftab){&ft_sfflag_j, &ft_sfconv_u},
	(t_sftab){&ft_sfflag_z, &ft_sfconv_u},
	(t_sftab){NULL, &ft_sfconv_u},
	(t_sftab){NULL, &ft_sfconv_s},
	(t_sftab){NULL, &ft_sfconv_c},
	(t_sftab){NULL, &ft_sfconv_n},
	(t_sftab){NULL, &ft_sfconv_u},
	(t_sftab){NULL, &ft_sfconv_n},
	(t_sftab){NULL, &ft_sfconv_n},
	(t_sftab){NULL, NULL}
};

#endif
