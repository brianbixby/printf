/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_signed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 05:44:20 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/17 05:44:26 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_print_signed(char *s, int *lenptr, t_print *print)
{
	int     i;
	int     charstoprint;
	int     size;
	char    *str;
    int     j;
    char    *prepend;
    int     prependl;

    // printf("%s %s \n", "s: ", s);
    prepend = NULL;
    prependl = 0;
    if (print->flag[3] && ft_atoi(s) && (print->type == 'o' || print->type == 'x' || print->type == 'X'))
    {
        if (print->type == 'o')
        {
            prepend = "0";
            prependl = 1;
        }
        else
        {
            prepend = (print->type == 'x' ? "0x" : "0X" );
            prependl = 2;
        }
    }
        
    j = 0;
    i = ft_strlen(s);
	// i = (print->prec != -1 && (print->type == 'o' || print->type == 'X' || print->type == 'x') ? print->prec : ft_strlen(s));
	charstoprint = i + prependl;
	size = (print->minw > charstoprint ? print->minw : charstoprint);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return ;
	str[size] = '\0';
	i = -1;
    if (print->flag[2])
    {
        str[0] = (s[0] == '-' ? '-' : '+');
        if (s[0] == '-')
            s++;
        i++;
    }
    else if (print->flag[4])
    {
        str[0] = (s[0] == '-' ? '-' : ' ');
        if (s[0] == '-')
            s++;
        i++;
    }
    // if (print->flag[3] && ft_atoi(s) && (print->type == 'o' || print->type == 'x' || print->type == 'X'))
    // {
    //     str[0] = 0;
    //     // write(1, "0", 1);
    //     *lenptr += 1;
    //     i++;
    //     if (print->type == 'x' || print->type == 'X')
    //     {
    //         str[1] = (print->type == 'x' ? 'x' : 'X');
    //         // print->type == 'x' ? write(1, "x", 1) : write(1, "X", 1);
    //         *lenptr += 1;
    //         i++;
    //     }
    // }
    if (prependl && (print->flag[0] || print->flag[1]))
    {
        str[0] = '0';
        if (prependl == 2)
            str[1] = prepend[1];
        i += prependl;
    }
	if (print->flag[0])
	{
        while (++i < charstoprint)
        {
			str[i] = s[j];
            j++;
        }
		while (i < size)
		{
			str[i] = ' ';
			i++;
		}
	}
	else
	{
        if (print->flag[1])
            charstoprint -= prependl;
		while (++i < size - charstoprint)
			str[i] = (print->flag[1] ? '0' : ' ');
        if (prependl && !print->flag[1])
        {
            str[i] = '0';
            i++;
            if (prependl == 2)
            {
                str[i] = prepend[1];
                i++;
            }
        }
		while (i < size)
		{
			str[i] = s[j];
			i++;
            j++;
		}
	}
	write(1, str, size);
	*lenptr += size;
	free(str);
}