/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_space_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:07:51 by akahir            #+#    #+#             */
/*   Updated: 2024/12/01 17:36:21 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	base_decimal(int value, int *count)
{
	char			c;

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
		base_decimal(value / 10, count);
	c = (value % 10) + '0';
	*count += write(1, &c, 1);
}

void	base_space(long long value, const char *format, int *count)
{
	if (*format == 'd')
	{
		*count += write(1, " ", 1);
		base_decimal((int)value, count);
	}
	else if (*format == 'i')
	{
		*count += write(1, " ", 1);
		base_decimal((int)value, count);
	}
}
