/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 07:54:25 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/10 07:54:28 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_printsinglechar(int i, int *lenptr)
{
	char    c;

	c = (char)i;
	write(1, &c, 1);
	*lenptr += 1;
}

void        ft_printchar(int i, int *lenptr, t_print *print)
{
	char    c;
	t_print	myprint;

	myprint = *print;
	c = (char)i;
	write(1, &c, 1);
	*lenptr += 1;
}

void        ft_printstr(char *s, int *lenptr)
{
	int     i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	*lenptr += i;
}

// void        ft_printhandler(char *s, int *lenptr, t_print *print)
// {
// 	char	prepend;

// 	prepend = ft_getprependval(s, print);
// }

// char		ft_getprependval(char *s, t_print *print)
// {
// 	if (print->type == 'i' || print->type == 'd')
// 	{
// 		if (print->flag[2])
//       		return (s[0] == '-' ? ('-') : ('+'));
//     	else if (print->flag[4])
//       		return (s[0] == '-' ? ('-') : (' '));
// 	}
// 	return (NULL);
// }