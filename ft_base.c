/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:48:15 by akahir            #+#    #+#             */
/*   Updated: 2024/12/01 17:36:38 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	base_hexa(const char *format, unsigned long value, int *count)
{
	char	c;
	char	*base;

	base = "0123456789abcdef";
	if (*format == 'X')
	{
		base = "0123456789ABCDEF";
	}
	else
	{
		base = "0123456789abcdef";
	}
	if (value >= 16)
	{
		base_hexa(format, value / 16, count);
	}
	c = base[value % 16];
	*count += write(1, &c, 1);
}

static void	ft_is_u(int value, int *count)
{
	unsigned int	nb;
	char			c;

	nb = (unsigned int)value;
	if (nb >= 10)
	{
		ft_is_u(nb / 10, count);
	}
	c = (nb % 10) + '0';
	*count += write(1, &c, 1);
}

static	void	base_decimal(int value, unsigned int is_u, int *count)
{
	char			c;

	if (is_u == 1)
	{
		ft_is_u(value, count);
	}
	else if (is_u == 0)
	{
		if (value == -2147483648)
		{
			*count += write(1, "-2147483648", 11);
			return ;
		}
		if (value < 0)
		{
			*count += write(1, "-", 1);
			value = -value;
		}
		if (value >= 10)
			base_decimal(value / 10, 0, count);
		c = (value % 10) + '0';
		*count += write(1, &c, 1);
	}
}

void	ft_base(long long value, const char *format, int *count)
{
	if (*format == 'd' || *format == 'i' || *format == 'u')
	{
		if (*format == 'u')
		{
			base_decimal((int)value, 1, count);
			return ;
		}
		base_decimal((int)value, 0, count);
	}
	else if (*format == 'p' || *format == 'x' || *format == 'X')
	{
		if (*format == 'p')
			*count += write(1, "0x", 2);
		base_hexa(format, (unsigned long)value, count);
	}
}
