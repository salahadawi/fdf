/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:27:35 by sadawi            #+#    #+#             */
/*   Updated: 2020/02/19 17:33:34 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_atoi(char const *str);

char				*ft_strcpy(char *dst, const char *src);

char				*ft_strncpy(char *dst, const char *src, size_t len);

char				*ft_strcat(char *s1, const char *s2);

char				*ft_strncat(char *s1, const char *s2, size_t n);

size_t				ft_strlcat(char *s1, const char *s2, size_t n);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

char				*ft_strstr(char const *haystack, char const *needle);

char				*ft_strnstr(const char *haystack, const char *needle, \
								size_t len);

int					ft_isalpha(int c);

int					ft_isascii(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

void				*ft_memset(void *b, int c, size_t len);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

char				*ft_strdup(const char *s1);

int					ft_strcmp(const char *s1, const char *s2);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s);

char				**ft_strsplit(char const *s, char c);

char				*ft_itoa(int n);

void				ft_putchar(char c);

void				ft_putstr(const char *s);

void				ft_putendl(const char *s);

void				ft_putnbr(int n);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(const char *s, int fd);

void				ft_putendl_fd(const char *s, int fd);

void				ft_putnbr_fd(int n, int fd);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_strfill(char *str, char c);

int					ft_lstevery(t_list *lst, int (*f)(t_list *elem));

void				ft_putlst(t_list *lst);

t_list				*ft_strsplitlst(const char *str, char c);

void				ft_swap(int *a, int *b);

void				ft_foreach(int *tab, int length, void(*f)(int));

int					ft_longlen(long int nbr);

void				ft_putlong(long int n);

void				ft_putulong(unsigned long int n);

char				*ft_itoa_base(long n, int base);

char				*ft_itoa_base_low(long n, int base);

char				*ft_itoa_base_ul(unsigned long n, int base);

char				*ft_itoa_base_ul_low(unsigned long n, int base);

void				ft_putdouble(long double d, int precision);

char				*ft_itoa_double(long double d, int precision);

char				*ft_chartostr(char c);

long				ft_atoilong(const char *str);

char				*ft_strjoinfree(char *s1, char *s2);

int					ft_isdigit_neg(char *str);

char				*ft_strcatfree(char *s1, const char *s2);

#endif
