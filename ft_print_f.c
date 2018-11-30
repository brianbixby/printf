// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_print_f.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2018/11/28 07:34:52 by bbixby            #+#    #+#             */
// /*   Updated: 2018/11/28 07:34:54 by bbixby           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "ft_printf.h"
#define ABS(i)  ((i < 0) ? (-i) : (i))

void        ft_print_f(char *s, int *lenptr, t_print *print)
{
    int r;
    int i;

    i = print->len_with_no_sign + print->neg - 2;
    r = (s[i + 1] - 48 >= 5 ? 1 : 0);
    if (print->prec)
    {
        while (i >= 0 && r)
        {
            if (s[i] == '9')
                s[i] = '0';
            else if (s[i] != '.')
            {
                s[i] += 1;
                r = 0;
            }
            i--;
        }
        if (r)
            write(1, "1", 1);
    }
    write(1, s, print->len_with_no_sign + print->neg -1);
    *lenptr += (print->len_with_no_sign + print->neg -1);
}

long long   powk(int x, unsigned int y)
{
    if( y == 0)
        return 1;
    else if (y%2 == 0)
        return powk(x, y/2)*powk(x, y/2);
    else
        return x*powk(x, y/2)*powk(x, y/2);
}
 

char    *ft_ldtoa(long double ld, t_print *print)
{
    long    long_ld;
    long long    mut_ab;
    unsigned long long    after_point_ld;
    long long    multiplier;
    long    xy;
    long long    muted;
    char    *str;
    char    *temp;
    int     i;
    
    i = 0;
    long_ld = (long) ld;
    ft_numlen(long_ld, print);
    if (!(str = (char *)malloc(sizeof(char) * (print->len_with_no_sign + print->neg + 1))))
        return (NULL);
    str[print->len_with_no_sign + print->neg] = '\0';
    temp = ft_lltoa((long long)ld);
    while (temp[i])
    {
        str[i] = temp[i];
        i++;
    }
    if (print->prec)
        str[i] = '.';
	mut_ab = powk(10, print->prec);
    after_point_ld = (unsigned long long) ABS(ld * mut_ab);
    multiplier = powk(10,(print->prec - 1));
    xy = 0;
    while (xy++ < print->prec)
    {
        muted = (after_point_ld/multiplier);
        muted = ABS(muted % 10);
        str[++i] = (char)muted + 48;
        multiplier/=10;
    }
    return (str);	
}

void    ft_numlen(long long_ld, t_print *print)
{
    long        denom;

    print->len_with_no_sign = 1;
    if (long_ld < 0)
        print->neg = 1;
    denom = 10;
    while (long_ld /= denom)
        print->len_with_no_sign++;
    if (print->prec)
        print->len_with_no_sign += (print->prec + 1);
}

char    *ft_lltoa(long long value)
{
	int             flag;
    int				size;
	char			*tab;
	long long	    tmp;
	char			*str;

    flag = (value < 0 ? 1 : 0);
	size = 1 + flag;
	tab = "0123456789abcdef";
	tmp = value;
	while (tmp /= 10)
		size++;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (size-- > flag)
	{
		str[size] = tab[ABS(value % 10)];
		value /= 10;
	}
    if (flag)
        str[0] = '-';
    return (str);
}