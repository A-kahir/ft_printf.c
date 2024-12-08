/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtag_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:25:23 by akahir            #+#    #+#             */
/*   Updated: 2024/12/08 16:49:24 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hashtag(const char *format, int *i, va_list list, int *count)
{
	unsigned int	x;

	if (format[*i] == 'c' || format[*i] == 's' || format[*i] == 'd'
		||format[*i] == 'i' || format[*i] == 'u' || format[*i] == '%')
		ft_handlers(format, i, list, count);
	if (format[*i] == 'p')
	{
		ft_handlers(format, i, list, count);
	}
	else if (format[*i] == 'x')
	{
		x = va_arg(list, unsigned int);
		base_hashtag(x, (char *)"x", count);
	}
	else if (format[*i] == 'X')
	{
		x = va_arg(list, unsigned int);
		base_hashtag(x, (char *)"X", count);
	}
}
