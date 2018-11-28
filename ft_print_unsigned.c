/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 07:41:46 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/11 07:41:47 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_print_unsigned(char *s, int *lenptr, t_print *print)
{
	int     i;
	int     charstoprint;
	int     size;
	char    *str;
	int		j;

	j = 0;
	i = ft_strlen(s);
	charstoprint = (print->prec == -1 || i > print->prec ? i : print->prec);
	size = (print->minw > charstoprint ? print->minw : charstoprint);
	if ((print->type == 'o' || print->type == 'x' || print->type == 'X' || print->type == 'd' || print->type == 'i' || print->type == 'u' || print->type == 'p') && !print->flag[3] && print->prec == 0 && !print->flag[1] && ft_strcmp(s, "0") == 0)
		size = print->minw;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return ;
	str[size] = '\0';
	i = -1;
	if ((print->type == 'o' || print->type == 'x' || print->type == 'X' || print->type == 'd' || print->type == 'i' || print->type == 'u' || print->type == 'p') && !print->flag[3] && print->prec == 0 && !print->flag[1] && ft_strcmp(s, "0") == 0)
	{
		while (++i < size)
      		str[i] = ' ';
	}
	else if (print->flag[0])
	{
		while (++i < charstoprint)
			str[i] = s[i];
		while (i < size)
		{
			str[i] = ' ';
			i++;
		}
	}
	else
	{
		while (++i < size - charstoprint)
			str[i] = (print->flag[1] ? '0' : ' ');
		while (i + print->len_with_no_sign < size)
        	str[i++] = '0';
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