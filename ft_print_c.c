/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:20:51 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/16 15:20:52 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_print_c(char c, int *lenptr, t_print *print)
{
    int     size;
    char    *ptr;
    int     idx;

    size = (1 > print->minw ? 1 : print->minw);
    if (!(ptr = (char *)malloc(sizeof(char) * (size + 1))))
        return ;
    ptr[size] = '\0';
    idx = 0;
    if (print->flag[0])
    {
        ptr[idx++] = c;
        while (idx < size)
            ptr[idx++] = ' ';
    }
    else
    {
        while (idx < size - 1)
            ptr[idx++] = (print->flag[1] ? '0' : ' ');
        ptr[idx] = c;
    }
    write(1, ptr, size);
	*lenptr += size;
    free(ptr);
}

// void        ft_print_c(char c, int *lenptr, t_print *print)
// {
// 	int     i;
// 	int		j;
// 	int     charstoprint;
// 	int     size;
// 	char    *str;
	
// 	i = 1;
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
// 			str[i] = c;
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
// 			str[i] = c;
// 			i++;
// 			j++;
// 		}
// 	}
// 	write(1, str, size);
// 	*lenptr += size;
// 	free(str);
// }
