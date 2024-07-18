/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:47:54 by adelille          #+#    #+#             */
/*   Updated: 2024/07/18 19:46:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "color.h"
# include "gfd.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdint.h>

# ifndef PB_BUFFER
#  define PB_BUFFER	40000
# endif

# ifndef GAL_INIT_BUFFER
#  define GAL_INIT_BUFFER	40000
# endif

# ifndef GAL_BUFFER
#  define GAL_BUFFER	280000
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_split_next
{
	size_t			start;
	size_t			len;
}					t_split_next;

/* is */
bool			ft_isascii(int c);
bool			ft_isdigit(int c);
bool			ft_isupper(int c);
bool			ft_islower(int c);
bool			ft_isalpha(int c);
bool			ft_isalnum(int c);

bool			ft_isprint(int c);
bool			ft_isspace(int c);

/* char */
int				ft_toupper(int c);
int				ft_tolower(int c);

/* nbr */
size_t			ft_abs(ssize_t n);

size_t			ft_nbrlen(ssize_t n);
size_t			ft_unbrlen(size_t n);

/* str */
size_t			ft_strlen(const char *str);

/* # search */
char			*ft_strchr(const char *s, int c);
// char			*ft_strnchr(const char *s, int c, size_t n);
char			*ft_strrchr(const char *s, int c);

// char			*ft_strstr(const char *s, const char *match);
char			*ft_strnstr(const char *s, const char *match, size_t len);
// char			*ft_strrstr(const char *s, const char *match);

/* # cmp */
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/* # cpy */
size_t			ft_strcpy(char *dst, const char *src);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strocpy(char *dst, const char *src, size_t size);

char			*ft_strdup(const char *s);
// char			*ft_strndup(const char *s, size_t n);

/* # cat */
// size_t			ft_strcat(char *dst, const char *src);
size_t			ft_strlcat(char *dst, const char *src, size_t size);

char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free(char *s1, char *s2, bool f1, bool f2);

/* mem */
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);

void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memset(void *s, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);

/* lst */

/* TODO */

int				ft_atoi(const char *nptr);
long			ft_atol(const char *nptr);
double			ft_atof(const char *str);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void*));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));

ssize_t			ft_ps(const char *str);
ssize_t			ft_psc(const char *str, const char *color);
ssize_t			ft_pser(const char *str);
ssize_t			ft_pserc(const char *str, const char *color);
ssize_t			ft_pn(int nbr);
ssize_t			ft_pner(int nbr);
ssize_t			ft_pnc(int nbr, const char *color);
ssize_t			ft_pnerc(int nbr, const char *color);

ssize_t			ft_prgb(const int r, const int g, const int b);
ssize_t			ft_prgb_b(const int r, const int g, const int b);

void			ft_pb(const bool w, const char *str);
void			ft_pb_s(const bool w, const char *str, const size_t size);
size_t			ft_pb_f(const bool w, const char *str);
bool			ft_pb_oms(const bool w, const char *str, const size_t size);
bool			ft_pb_omsa(const bool w, const char *str, const size_t size);

char			*ft_str_extend(char *str, const size_t size,
					const size_t capacity);

char			*gal(const int fd, size_t *size, const bool all);

#endif
