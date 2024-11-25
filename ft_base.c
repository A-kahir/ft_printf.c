/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <aymanekahir036@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:00:29 by akahir            #+#    #+#             */
/*   Updated: 2024/11/25 21:56:20 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void base_Hexa(unsigned long value, const char *base, int *count)
{
    char c;
    
    if (value >= 16)
    {
        base_Hexa(value / 16, base, count);
    }
    c = base[value % 16];
    *count += write(1, &c, 1);
}
static void base_Decimal(int value, unsigned int is_u, int *count)
{
    char c;
    unsigned int nb;

    if (is_u == 1)
    {
        nb = (unsigned int)value;
        if (nb >= 10)
        {
            base_Decimal(nb / 10, 1, count);
        }
        c = (nb % 10) + '0';
        *count += write(1, &c, 1);
    }
    else if (is_u == 0)
    {
        if (value == -2147483648)
        {
            *count += write(1, "-2147483648", 11);
            return;
        }
        if (value < 0)
        {
            *count += write(1, "-", 1);
            value = value * -1;
        }
        if (value >= 10)
        {
            base_Decimal(value / 10, 1, count);
        }
        c = (value % 10) + '0';
        *count += write(1, &c, 1);
    }
}

void ft_base(unsigned long value,const char *format, const char *base, int *count)
{
    if (*format == 'd' || *format == 'i' || *format == 'u')
    {
        if (*format == 'u')
        {
            base_Decimal(value, 1,count);
            return;
        }
        base_Decimal(value, 0,count);
    }
    else if (*format == 'x' || *format == 'X' || *format == 'p')
    {
       base_Hexa(value, base, count);
    }
}
