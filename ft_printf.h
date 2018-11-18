/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 06:48:45 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/10 06:48:46 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <locale.h>
# include <stdio.h>

typedef struct		s_print
{
	int				flag[5];
	int				minw;
	int				prec;
	int				len;
	char			type;
}					t_print;

char        *ft_lltoa_base(long long value, int base, t_print *print);
char        *ft_ulltoa_base(unsigned long long value, int base, t_print *print);
void				ft_format(va_list ap, t_print *print, int *lenptr);
int					ft_printf(const char *s, ...);
long long   ft_int_modifier(va_list ap, t_print *print);
unsigned long long   ft_uint_modifier(va_list ap, t_print *print);

const char	*ft_setflags(const char *s, va_list ap, int *lenptr);
void				ft_initializeprintstruct(t_print *print);

// ft_print.c
void        ft_printsinglechar(int i, int *lenptr);
void				ft_printchar(int i, int *lenptr, t_print *print);
void				ft_printstr(char *s, int *lenptr);
// char		ft_getprependval(char *s, t_print *print);

// ft_helpers.c
int					ft_atoi(const char *str);
int					ft_strlen(char *s);

// ft_wchar.c
size_t  ft_wcharlen(wchar_t w);
size_t	ft_wstrlen(wchar_t *s);
char    *ft_convertwchar(wchar_t wc);
char    *ft_convertwstr(wchar_t *wstr);

// ft_print_s.c
void        ft_print_s(char *s, int *lenptr, t_print *print);

// ft_print_c.c
void        ft_print_c(char c, int *lenptr, t_print *print);

// ft_print_unsigned.c
void        ft_print_unsigned(char *s, int *lenptr, t_print *print);

// ft_print_signed.c
void        ft_print_signed(char *s, int *lenptr, t_print *print);
#endif
