/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 06:48:34 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/10 06:48:36 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BASE(c) ((c == 'x' || c == 'X') ? (16) : (8))
#define ABS(i)  ((i < 0) ? (-i) : (i))
// #define FT_ULLMAX 18446744073709551615
// #define FT_LLMAX 9223372036854775807
// #define FT_LLMIN −9223372036854775808
char	*ft_lltoa_base(long long value, int base, t_print *print)
{
	// printf("%s %lld \n", "lltoa val: ", value);
	int             size;
	char            *tab;
	long long   	tmp;
	char			*str;

	size = 1;
	tab = (print->type == 'X' ? ("0123456789ABCDEF") : ("0123456789abcdef"));
	if (base < 2 || base > 16)
		return (NULL);
	tmp = value;
	while (tmp /= base)
		size++;
	if (value < 0)
	{
		print->neg = 1;
		print->prepend_val = "-";
		print->prepend = 1;
	}
	if (value == INTMAX_MIN)
	{
		print->len_with_no_sign = 19;
		size = -1;
		return (ft_strdup("9223372036854775808"));
	}
	// tmp = (value < 0 ? (1) : (0));
	// if (!(str = (char *)malloc(sizeof(char) * (size + tmp + 1))))
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	// while (size-- > tmp)
	// if (value == INTMAX_MAX)
	// {
	// 	return (ft_strdup());
	// }
	while (size-- > 0)
	{
		str[size] = tab[ABS(value % base)];
		value /= base;
	}
	// if (tmp)
	// 	str[0] = '-';
	// ft_printstr(str, lenptr, print);

	// ft_print_signed(str, lenptr, print);

	// ft_print_s(str, lenptr, print);
	print->len_with_no_sign = ft_strlen(str);
	return (str);
}

char	*ft_ulltoa_base(unsigned long long value, int base, t_print *print)
{
	// printf("%s %lld \n", "lltoa val: ", value);
	unsigned long long             size;
	char            *tab;
	unsigned long long   	tmp;
	char			*str;

	size = 1;
	tab = (print->type == 'X' ? ("0123456789ABCDEF") : ("0123456789abcdef"));
	if (base < 2 || base > 16)
		return (NULL);
	tmp = value;
	while (tmp /= base)
		size++;
	if (!(str = (char *)malloc(sizeof(char) * (size + tmp + 1))))
		return (NULL);
	str[size] = '\0';
	if (print->flag[3] && (print->type == 'o' || print->type == 'x' || print->type == 'X') && value != 0)
	{
		if (print->type == 'o')
		{
			print->prepend_val = "0";
			print->prepend = 1;
		}
		else
		{
			print->prepend_val = (print->type == 'x' ? "0x" : "0X");
			print->prepend = 2;
		}
	}
	while (size-- > tmp)
	{
		str[size] = tab[ABS(value % base)];
		value /= base;
	}
	if (tmp)
		str[0] = '-';
	// ft_printstr(str, lenptr, print);

	// ft_print_s(str, lenptr, print);
	// printf("%s %s", "ultoabase str: ", str);
	print->len_with_no_sign = ft_strlen(str);
	return (str);
}

void		ft_format(va_list ap, t_print *print, int *lenptr)
{
	if (print->type == 's' || print->type == 'S')
		ft_print_s(va_arg(ap, char *), lenptr, print);
	else if (print->type == 'c' || print->type == 'C' || print->type == '%')
		print->type == 'c' || print->type == 'C' ? (ft_print_c(va_arg(ap, int), lenptr, print)) :
			(ft_print_s("%", lenptr, print));
	else if (print->type == 'p')
	{
		print->prepend_val = "0x";
		print->prepend = 2;
		ft_print_p(ft_lltoa_base((long long)va_arg(ap, void *), 16, print), lenptr, print);
	}
	else if (print->type == 'd' || print->type == 'i')
		ft_print_signed(ft_lltoa_base(ft_int_modifier(ap, print), 10, print), lenptr, print);
	else if (print->type == 'D')
		ft_print_signed(ft_lltoa_base((long)va_arg(ap, long), 10, print), lenptr, print);
	else if (print->type == 'u' || print->type == 'U')
	{
		print->flag[2] = 0;
		print->flag[4] = 0;
		print->prepend = 0;
		print->prepend_val = 0;
		ft_print_unsigned(ft_ulltoa_base(ft_uint_modifier(ap, print), 10, print), lenptr, print);
	}
	else if (print->type == 'o' || print->type == 'O' || print->type == 'x' || print->type == 'X')
	{
		print->flag[2] = 0;
		print->flag[4] = 0;
		print->prepend = 0;
		print->prepend_val = 0;
		ft_print_signed(ft_ulltoa_base(ft_uint_modifier(ap, print),  BASE(print->type), print), lenptr, print);
	}
	// else if (print->type == 'f')
	else
		ft_print_c((int)print->type, lenptr, print);
}

int         ft_printf(const char *s, ...)
{
	va_list     ap;
	int         len;
	int         *lenptr;
	int			idx;
	setlocale(LC_ALL, "en_US.UTF-8");

	va_start(ap, s);
	len = 0;
	lenptr = &len;
	idx = -1;
	while (s[++idx])
	{
		if (s[idx] != '%')
			ft_printsinglechar((int)s[idx], lenptr);
		else
		{
			idx++;
			// printf("%s %s \n", "before ft_setflags: ", &s[idx]);
			s = ft_setflags(&s[idx], ap, lenptr);
			idx = -1;
			// ft_format(ap, s[idx], lenptr);
		}
	}
	va_end(ap);
	return (len);
}

void	ft_initializeprintstruct(t_print *print)
{
	int		i;

	i = -1;
	while (++i < 5)
		print->flag[i] = 0;
	print->minw = 0;
	print->prec = -1;
	print->len = 0;
	print->type = 0;
	print->len_with_no_sign = 0;
	print->neg = 0;
	print->prepend = 0;
	print->prepend_val = 0;
}

const char		*ft_setflags(const char *s, va_list ap, int *lenptr)
{
	// printf("hit\n");
	// printf("%s %s \n", "ft_setflags: ", s);
	int			idx;
	t_print		print;

	idx = -1;
	ft_initializeprintstruct(&print);
	while (s[++idx])
	{
		while (s[idx] && (s[idx] == '-' || s[idx] == '0'  || s[idx] == '+' || s[idx] == '#' || s[idx] == ' '))
		{
			if (s[idx] == '-')
				print.flag[0] = 1;
			else if (s[idx] == '0')
				print.flag[1] = 1;
			else if (s[idx] == '+')
				print.flag[2] = 1;
			else if (s[idx] == '#')
				print.flag[3] = 1;
			else if (s[idx] == ' ')
				print.flag[4] = 1;
			idx++;
		}
		if (print.flag[2] || print.flag[4])
		{
			print.prepend_val = (print.flag[2] ? "+" : " ");
			print.prepend = 1;
		}
		if (s[idx] == '*')
		{
			print.minw = va_arg(ap, int);
			// printf("%s %d \n", "minw: ", print.minw);
			idx++;
		}
		else if (s[idx] >= '0' && s[idx] <= '9')
		{
			print.minw = ft_atoi(&s[idx]);
			while (s[idx] >= '0' && s[idx] <= '9')
				idx++;
		}
		if (s[idx] == '.')
		{
			idx++;
			if (s[idx] == '*')
			{
				print.prec = va_arg(ap, int);

				idx++;
			}
			else if (s[idx] >= '0' && s[idx] <= '9')
			{
				print.prec = ft_atoi(&s[idx]);
				while (s[idx] >= '0' && s[idx] <= '9')
					idx++;
			}
			else
				print.prec = 0;
		}
		if (s[idx] == 'h' && (s[idx +1] && s[idx + 1] == 'h'))
		{
			print.len = 1;
			idx += 2;
		}
		else if (s[idx] == 'h')
		{
			print.len = 2;
			idx++;
		}
		else if (s[idx] == 'l' && (s[idx +1] && s[idx + 1] == 'l'))
		{
			print.len = 3;
			idx += 2;
		}
		else if (s[idx] == 'l')
		{
			print.len = 4;
			idx++;
		}
		else if (s[idx] == 'j')
		{
			print.len = 5;
			idx++;
		}
		else if (s[idx] == 'z')
		{
			print.len = 6;
			idx++;
		}
		print.type = s[idx];
		// printf("%s %d%d%d%d%d %s %d %s %d %s %d %s %c \n", "flag[0]-[4]: ", print.flag[0],print.flag[1],print.flag[2],print.flag[3],print.flag[4], "minw: ", print.minw, "prec: ", print.prec, "len: ", print.len, "type: ", print.type);
		ft_format(ap, &print, lenptr);
		// printf("%s %s \n", "end ft_setflags: ", &s[idx]);
		return (&s[idx + 1]);
	}
	printf("shold not have hit this\n");
	return (&s[idx]);
}

// promoting to int instead of char and unsigned char because va_arg automatically promotes it to an int
long long   ft_int_modifier(va_list ap, t_print *print)
{
	long long	ret;

	ret = 0;
	if (print->len == 1)
		ret = (signed char)va_arg(ap, int);
	else if (print->len == 2)
		ret = (short)va_arg(ap, int);
	else if (print->len == 3)
		ret = (long long)va_arg(ap, long long);
	else if (print->len == 4)
		ret = (long)va_arg(ap, long);
	else if (print->len == 5)
		ret = (long long)va_arg(ap, long long);
	else if (print->len == 6)
		ret = (ssize_t)va_arg(ap, ssize_t);
	else
		ret = va_arg(ap, int);
	// printf("\n %s %lld \n", "int mod: ", ret);
	return (ret);
}

unsigned long long   ft_uint_modifier(va_list ap, t_print *print)
{
	unsigned long long	ret;

	ret = 0;
	if (print->len == 1)
		ret = (unsigned char)va_arg(ap, unsigned int);
	else if (print->len == 2)
		ret = (unsigned short)va_arg(ap, unsigned int);
	else if (print->len == 3)
		ret = (unsigned long long)va_arg(ap, unsigned long long);
	else if (print->len == 4)
		ret = (unsigned long)va_arg(ap, unsigned long);
	else if (print->len == 5)
		ret = (unsigned long long)va_arg(ap, unsigned long long);
	else if (print->len == 6)
		ret = (size_t)va_arg(ap, size_t);
	else
		ret = va_arg(ap, unsigned int);
	// printf("\n %s %lu \n", "uint mod: ", ret2);
	return (ret);
}