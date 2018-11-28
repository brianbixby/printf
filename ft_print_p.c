#include "ft_printf.h"

void        ft_print_p(char *s, int *lenptr, t_print *print)
{
    int     len;
    int     size;
    char    *ptr;
    int     idx;
    int     prepend_dup;

    prepend_dup = print->prepend;
    if (!s)
	{
		write(1, "(null)", 6);
		*lenptr += 6;
		return ;
	}
    // len = (print->prec == -1 || ft_strlen(s) > print->prec ? ft_strlen(s) + print->prepend : print->prec + print->prepend);
    len = (print->prec == -1 || print->prec < ft_strlen(s) ? ft_strlen(s) + print->prepend : print->prec + print->prepend);
    size = (len > print->minw ? len : print->minw);
    if (!(ptr = (char *)malloc(sizeof(char) * (size + 1))))
        return ;
    ptr[size] = '\0';
    idx = -1;
    if (print->flag[0])
    {
        while (print->prepend--)
            ptr[++idx] = *(print->prepend_val++);
        while (idx < len && *s)
            ptr[++idx] = *s++;
        while (idx++ < size)
            ptr[idx] = ' ';
    }
    else
    {
        // while (idx + print->prepend < size - len)
        while (idx + 1 < size - len)
            ptr[++idx] = (print->flag[1] ? '0' : ' ');
        while (print->prepend--)
            ptr[++idx] = *(print->prepend_val++);
        if (print->prec > ft_strlen(s))
            while (idx + 1 < size - ft_strlen(s))
                ptr[++idx] = '0';
        while (*s && idx + 1 < size)
            ptr[++idx] = *s++;
    }
    write(1, ptr, size);
	*lenptr += size;
    free(ptr);
	// if (print->type == 'p')
	// 	free(s);
}