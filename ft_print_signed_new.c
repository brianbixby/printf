#include "ft_printf.h"

// void        ft_print_signed(char *s, int *lenptr, t_print *print)
// {
//     int     len;
//     int     size;
//     char    *ptr;
//     int     idx;
//     int     flag;
//     int     len_with_no_sign;

//     len = ft_strlen(s);
//     flag = 0;
//     len_with_no_sign = (s[0] != '-' ? len : len - 1);
//     if ((print->flag[2] || print->flag[4]) && s[0] != '-')
//         len += 1;
//     size = (len > print->minw ? len : print->minw);
//     if (!(ptr = (char *)malloc(sizeof(char) * (size + 1))))
//         return ;
//     ptr[size] = '\0';
//     idx = -1;
//     if (print->flag[2] || print->flag[4])
//     {
//         if (print->flag[2])
//             ptr[++idx] = (s[0] != '-' ? '+' : '-');
//         else 
//             ptr[++idx] = (s[0] != '-' ? ' ' : '-');
//         if (s[0] != '-')
//             flag = -1;
//     }
//     if (print->flag[0])
//     {
//         while (s[++idx + flag])
//             ptr[idx] = s[idx + flag];
//         while (idx < size)
//             ptr[idx++] = ' ';
//     }
//     else
//     {
//         if (print)
//         // if (!print->flag[1] &&)
//         while (++idx + len_with_no_sign < size)
//         {

//         }
//         ptr[idx] = (print->flag[1] ? '0' : ' ');
        
//     }
//     write(1, ptr, size);
//     *lenptr += size;
//     free(ptr);
// }

// void        ft_print_signed(char *s, int *lenptr, t_print *print)
// {
//     int     len;
//     int     size;
//     char    *ptr;
//     int     idx;

//     len = ft_strlen(s);
//     size = (len > print->minw ? len : print->minw);
//     if (!(ptr = (char *)malloc(sizeof(char) * (size + 1))))
//         return ;
//     ptr[size] = '\0';
//     idx = -1;
//     if (print->flag[0])
//     {
//         while (s[++idx])
//             ptr[idx] = s[idx];
//         while (idx < size)
//             ptr[idx++] = ' ';
//     }
//     else
//     {
//         while (++idx < size - len)
//             ptr[idx] = ' ';
//         while (*s)
//             ptr[idx++] = *s++;
//     }
//     write(1, ptr, size);
// 	*lenptr += size;
//     free(ptr);
// }