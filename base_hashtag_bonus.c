/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_hashtag_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:42:21 by akahir            #+#    #+#             */
/*   Updated: 2024/12/01 17:35:59 by akahir           ###   ########.fr       */
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

void	base_hashtag(long long value, const char *format, int *count)
{
	if (*format == 'x')
	{
		*count += write(1, "0x", 2);
		base_hexa(format, (unsigned long)value, count);
	}
	else if (*format == 'X')
	{
		*count += write(1, "0X", 2);
		base_hexa(format, (unsigned long)value, count);
	}
}
