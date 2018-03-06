/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzaim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:30:06 by wzaim             #+#    #+#             */
/*   Updated: 2018/01/04 12:55:19 by wzaim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <limits.h>
# define BUFF_SIZE 32

extern char	*g_sizes[2][6];
extern char	*g_conv[2][15];

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** idx ==> Position du flag et donc de l'endroit ou inserer
*/
typedef struct	s_caracs
{
	int		length;
	int		raw_len;
	int		hasopt;
	int		space;
	int		hash;
	int		plus;
	int		minus;
	int		zero;
	int		width;
	int		prec;
	char	*size;
	char	conv;
	int		convidx;
	char	*type;
	int		base;
	int		isdef;
	int		isneg;
	int		ischarnull;
	int		isrelou;
	int		canczero;
	int		hasdot;
	char	padchar;
	char	*raw_output;
	char	*final;
}				t_caracs;

/*
** PRINTF RELATED
*/
int				main(int argc, char **argv);
int				ft_printf(const char *fmt, ...);
int				ft_printf_rec(const char *fmt, int final, va_list ap);

int				myfree(t_caracs *input, char **mystr, int flag);
void			flag0free(t_caracs *input, char **mystr);
void			flag2free(t_caracs *input);
void			pf_my_alloc(t_caracs **input);

int				pf_parse(const char *format, va_list ap, t_caracs *input);
int				pf_find_conv(const char *fmt, t_caracs *input);
int				pf_issize(const char *format, int flag);
int				pf_find_opts(const char *format, t_caracs *input);
void			pf_get_prec(const char *fmt, t_caracs *input, va_list ap);
int				pf_get_width(const char *format, t_caracs *input, va_list ap);
int				pf_get_type(t_caracs *input);

void			pf_init_globals(void);
void			pf_init_globals2(void);
void			pf_struct_init(t_caracs *input);

int				pf_get_output(t_caracs *input, va_list ap);
void			pf_get_output2(t_caracs *input, va_list ap);
void			pf_get_output3(t_caracs *input, va_list ap);

int				pf_convert_d(t_caracs *input);
int				pf_convert_s(t_caracs *input);
int				pf_convert_c(t_caracs *input);
int				pf_convert_oux(t_caracs *input);
int				pf_convert_capsc(t_caracs *input);
int				pf_convert_real_u(t_caracs *input);

int				pf_calculs(t_caracs *input);
int				pf_percent(t_caracs *input);
int				pf_convidx(t_caracs *input);

int				pf_handle_di(t_caracs *input);
void			pf_handle_sbigs(t_caracs *input);
void			pf_handle_xo(t_caracs *input);
void			pf_handle_cnull(t_caracs *input);

void			pf_fill_output_di(t_caracs *input);
void			pf_fill_minus_di(t_caracs *input);
void			pf_fill_s_minus(t_caracs *input, int nb_char, int to_copy);
void			pf_fill_xo(t_caracs *input, int nb_char);
void			pf_fill_minus_xo(t_caracs *input, int nb_char);

void			pf_copy_cnull(t_caracs *input, int nb_char, int to_copy);

void			pf_rework_struct(t_caracs *input);
void			pf_rework_struct2(t_caracs *input);
void			pf_rework_struct3(t_caracs *input);
void			pf_rework_struct4(t_caracs *input);
void			pf_rework_struct5(t_caracs *input);

void			pf_add_hash(t_caracs *input, int i);
void			pf_p_hash(t_caracs *input);
int				pf_ishash(t_caracs *input);
void			pf_add_sign(t_caracs *input, int i);

void			pf_add_null(char *dest, t_caracs *input, int p);
void			pf_copy_body(char *dest, t_caracs *input, int p);
char			*pf_insert_str(t_caracs *input, const char *format, int p);
void			pf_get_length(t_caracs *input);

void			convert_wide_c(t_caracs *input, va_list ap);
void			convert_wide_s(t_caracs *input, va_list ap);
char			*wide_to_str(wint_t c);

int				ft_clean_write_null(const char *s, int isnull, int max);
int				ft_write_ichar(const char *s, int n);
int				ft_write_nullchar(const char *s);

char			*pf_get_ascii(int nb);
void			pf_check_null(t_caracs *input, va_list ap);
int				pf_xo_tester(t_caracs *input, int j);
int				pf_xo_tester2(t_caracs *input);
int				pf_xo_tester3(t_caracs *input);
int				pf_xo_tester4(t_caracs *input, int j);

/*
** MISCELLANEOUS AND GNL
*/
void			ft_exit(void);
int				get_next_line(const int fd, char **line);

/*
** BOOLEANS
*/
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_is_include(char **argv, char *needle, size_t n);
int				ft_is_prime(int nb);
int				ft_isonlyblank(char *str);

/*
** CHAR MODIFIERS
*/
int				ft_tolower(int c);
int				ft_toupper(int c);

/*
** STR FUNCTIONS
*/
size_t			ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_strclr(char *s);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strdup(const char *s);
char			*ft_strndup(const char *s, size_t n);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
int				ft_strichr(const char *s, int c);
int				ft_strichrn(const char *s, int c, int n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			**ft_strsplit(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
int				ft_clean_write(char const *s, int isnull);
void			ft_strcapitalize(char *s);
/*
** ATOI FAMILY
*/
int				ft_atoi(const char *str);
char			*ft_itoa(long long n);
char			*ft_itoa_ul(unsigned long n);
char			*ft_itoa_ull(uintmax_t n);
char			*ft_itoa_base(long long n, int base);
char			*ft_itoa_base_ull(uintmax_t n, int base);
long			ft_atoi_l(const char *str);
long long		ft_atoi_ll(const char *str);

/*
** DISPLAY FUNCTIONS
*/
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** MEMORY RELATED FUNCTIONS
*/
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

/*
** LIST RELATED FUNCTIONS
*/
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));

/*
** MATH FUNCTIONS
*/
int				ft_power(int nb, int power);
int				ft_sqrt(int nb);
size_t			ft_get_nb_digits(long long n, int base);

#endif
