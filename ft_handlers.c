/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <aymanekahir036@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:11:46 by akahir            #+#    #+#             */
/*   Updated: 2024/11/25 22:06:32 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void  ft_handlers(const char *format, int i, va_list list, int *count)
{
    if (format[i + 1] == 'c')
    {
        char c = (char)va_arg(list, int);
        *count += write(1, &c, 1);
    }
    else if (format[i + 1] == 's')
    {
        char *str = va_arg(list, char *);
        *count += write(1, str, ft_strlen(str));
    }
    else if (format[i + 1] == 'p')
    {
        void *ptr = va_arg(list, void *);
        if (!ptr)
        {
            *count += write(1, "(nil)", 5);
            return ;
        }
        *count += write(1, "0x", 2);
        ft_base((unsigned long)ptr, (char *)"p", "0123456789abcdef", count);
    }
    else if (format[i + 1] == 'd')
    {
        int nb = va_arg(list, int);
        ft_base(nb, (char *)"d","0123456789", count);
    }
    else if (format[i + 1] == 'i')
    {
        int nb = va_arg(list, int);
        ft_base(nb, (char *)"i","0123456789", count);
    }
    else if (format[i + 1] == 'u')
    {
        unsigned int u = va_arg(list, unsigned int);
        ft_base(u, (char *)"u","0123456789", count);
    }
    else if (format[i + 1] == 'x')
    {
        
        int x = va_arg(list, unsigned int);
        ft_base(x, (char *)"x","0123456789abcdef", count);
    }
    else if (format[i + 1] == 'X')
    {
        int X = va_arg(list, unsigned int);
        ft_base(X, (char *)"X","0123456789ABCDEF", count);
    }
    else if (format[i + 1] == '%')
    {
        *count += write(1, "%", 1);
    }
}
