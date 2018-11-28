/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 06:57:47 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/11 06:57:48 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_print_s(char *s, int *lenptr, t_print *print)
{
    int     len;
    int     size;
    char    *ptr;
    int     idx;

    if (!s)
	{
		write(1, "(null)", 6);
		*lenptr += 6;
		return ;
	}
    len = (print->prec == -1 || print->type == '%' || ft_strlen(s) < print->prec ? ft_strlen(s) : print->prec);
    // len = ((print->prec != -1 || print->type != '%') && print->prec < ft_strlen(s) ? print->prec : ft_strlen(s));
    size = (len > print->minw ? len : print->minw);
    if (!(ptr = (char *)malloc(sizeof(char) * (size + 1))))
        return ;
    ptr[size] = '\0';
    idx = -1;
    if (print->flag[0])
    {
        while (++idx < len && s[idx])
            ptr[idx] = s[idx];
        while (idx < size)
            ptr[idx++] = ' ';
    }
    else
    {
        while (++idx < size - len)
            ptr[idx] = ' ';
        while (*s && idx < size)
            ptr[idx++] = *s++;
    }
    write(1, ptr, size);
	*lenptr += size;
    free(ptr);
	// if (print->type == 'p')
	// 	free(s);
}

// void        ft_print_s(char *s, int *lenptr, t_print *print)
// {
	
// 	// printf("%s %d %d %d %d %d \n", "flag: ", print->flag[0], print->flag[1], print->flag[2], print->flag[3], print->flag[4]);
// 	// printf("%s %d \n %s %d \n %s %d \n %s %c \n", "minw: ", print->minw, "prec: ", print->prec, "len: ", print->len, "type: ", print->type);
// 	int     i;
// 	int		j;
// 	int     charstoprint;
// 	int     size;
// 	char    *str;
	
// 	if (!s)
// 	{
// 		write(1, "(null)", 6);
// 		*lenptr += 6;
// 		return ;
// 	}
// 	i = ft_strlen(s);
// 	j = 0;
// 	charstoprint = (print->prec == -1 || print->prec > i ? i : print->prec);
// 	size = (print->minw > charstoprint ? print->minw : charstoprint);
// 	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
// 		return ;
// 	str[size] = '\0';
// 	i = -1;
// 	if (print->flag[0])
// 	{
// 		while (++i < charstoprint)
// 			str[i] = s[i];
// 		while (i < size)
// 		{
// 			str[i] = ' ';
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while (++i < size - charstoprint)
// 			str[i] = ' ';
// 		while (i < size)
// 		{
// 			str[i] = s[j];
// 			i++;
// 			j++;
// 		}
// 	}
// 	write(1, str, size);
// 	*lenptr += size;
// 	free(str);
// }
