/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:58:11 by bbixby            #+#    #+#             */
/*   Updated: 2018/12/03 15:58:14 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"
#include <limits.h>

int		main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	printf("%#.3o\n", 1);
	ft_printf("%#.3o\n", 1);
	return (0);
}
