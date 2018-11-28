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
  int     size;
  char    *ptr;
  int pidx;
  int sidx;

  size = (print->len_with_no_sign + print->prepend > print->minw ? print->len_with_no_sign + print->prepend : print->minw);
  if (print->prec + print->prepend > size)
    size = print->prec + print->prepend;
  if (print->prec == 0 && ft_strcmp(s, "0") == 0)
    size = print->minw;
  if (!(ptr = (char *)malloc(sizeof(char) * (size + 1))))
      return ;
  ptr[size] = '\0';
  pidx = -1;
  sidx = -1;
  if (print->prec == 0 && ft_strcmp(s, "0") == 0)
  {
    while (++pidx < size)
      ptr[pidx] = ' ';
  }
  else if (print->flag[0])
  {
    if (print->neg)
      ptr[++pidx] = '-';
    else if (print->flag[2] || print->flag[4])
      ptr[++pidx] = (print->flag[2] ? '+' : ' ');
    if (print->type == 'x' || print->type == 'X' ||print->type == 'o')
      while (print->prepend--)
        ptr[++pidx] = *(print->prepend_val++);
    while (--print->prec - print->len_with_no_sign >= 0)
      ptr[++pidx] = '0';
    while (s[++sidx])
      ptr[++pidx] = s[sidx];
    while (++pidx < size)
      ptr[pidx] = ' ';
  }
  else
  {
    if (print->flag[1] && print->prec == -1)
    {
      // if (print->neg)
      //   ptr[++pidx] = '-';
      // else if (print->flag[2] || print->flag[4])
      //   ptr[++pidx] = (print->flag[2] ? '+' : ' ');
      while (print->prepend--)
        ptr[++pidx] = *(print->prepend_val++);
      while (pidx + print->len_with_no_sign + 1 < size)
        ptr[++pidx] = '0';
      while (s[++sidx])
          ptr[++pidx] = s[sidx];
    }
    else if (print->prec > print->len_with_no_sign)
    {
      while (pidx + 1 + print->prepend + print->prec < size)
        ptr[++pidx] = ' ';
      while (print->prepend--)
        ptr[++pidx] = *(print->prepend_val++);
      while (pidx + 1 + print->len_with_no_sign < size)
        ptr[++pidx] = '0';
      while (++pidx < size)
        ptr[pidx] = s[++sidx];
    }
    else
    {
        while (pidx + 1 + print->prepend + print->len_with_no_sign < size)
            ptr[++pidx] = ' ';
        while (print->prepend--)
            ptr[++pidx] = *(print->prepend_val++);
        while (++pidx < size)
            ptr[pidx] = s[++sidx];
    }
  }
  write(1, ptr, size);
  *lenptr += size;
  free(ptr);
}

// void        ft_print_signed(char *s, int *lenptr, t_print *print)
// {
// 	int     i;
// 	int     charstoprint;
// 	int     size;
// 	char    *str;
//     int     j;
//     char    *prepend;
//     int     prependl;

//     // printf("%s %s \n", "s: ", s);
//     prepend = NULL;
//     prependl = 0;
//     if (print->flag[3] && ft_atoi(s) && (print->type == 'o' || print->type == 'x' || print->type == 'X'))
//     {
//         if (print->type == 'o')
//         {
//             prepend = "0";
//             prependl = 1;
//         }
//         else
//         {
//             prepend = (print->type == 'x' ? "0x" : "0X" );
//             prependl = 2;
//         }
//     }
        
//     j = 0;
//     i = ft_strlen(s);
// 	// i = (print->prec != -1 && (print->type == 'o' || print->type == 'X' || print->type == 'x') ? print->prec : ft_strlen(s));
// 	charstoprint = i + prependl;
// 	size = (print->minw > charstoprint ? print->minw : charstoprint);
// 	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
// 		return ;
// 	str[size] = '\0';
// 	i = -1;
//     if (print->flag[2])
//     {
//         str[0] = (s[0] == '-' ? '-' : '+');
//         if (s[0] == '-')
//             s++;
//         i++;
//     }
//     else if (print->flag[4])
//     {
//         str[0] = (s[0] == '-' ? '-' : ' ');
//         if (s[0] == '-')
//             s++;
//         i++;
//     }
//     // if (print->flag[3] && ft_atoi(s) && (print->type == 'o' || print->type == 'x' || print->type == 'X'))
//     // {
//     //     str[0] = 0;
//     //     // write(1, "0", 1);
//     //     *lenptr += 1;
//     //     i++;
//     //     if (print->type == 'x' || print->type == 'X')
//     //     {
//     //         str[1] = (print->type == 'x' ? 'x' : 'X');
//     //         // print->type == 'x' ? write(1, "x", 1) : write(1, "X", 1);
//     //         *lenptr += 1;
//     //         i++;
//     //     }
//     // }
//     if (prependl && (print->flag[0] || print->flag[1]))
//     {
//         str[0] = '0';
//         if (prependl == 2)
//             str[1] = prepend[1];
//         i += prependl;
//     }
// 	if (print->flag[0])
// 	{
//         while (++i < charstoprint)
//         {
// 			str[i] = s[j];
//             j++;
//         }
// 		while (i < size)
// 		{
// 			str[i] = ' ';
// 			i++;
// 		}
// 	}
// 	else
// 	{
//         if (print->flag[1])
//             charstoprint -= prependl;
// 		while (++i < size - charstoprint)
// 			str[i] = (print->flag[1] ? '0' : ' ');
//         if (prependl && !print->flag[1])
//         {
//             str[i] = '0';
//             i++;
//             if (prependl == 2)
//             {
//                 str[i] = prepend[1];
//                 i++;
//             }
//         }
// 		while (i < size)
// 		{
// 			str[i] = s[j];
// 			i++;
//             j++;
// 		}
// 	}
// 	write(1, str, size);
// 	*lenptr += size;
// 	free(str);
// }