/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:15:55 by akahir            #+#    #+#             */
/*   Updated: 2024/12/08 16:50:06 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	plus(const char *format, int *i, va_list list, int *count)
{
	int		nb;

	if (format[*i] == 'c' || format[*i] == 's'
		|| format[*i] == 'p' || format[*i] == 'u'
		|| format[*i] == 'x' || format[*i] == 'X' || format[*i] == '%')
		ft_handlers(format, i, list, count);
	if (format[*i] == 'd')
	{
		nb = va_arg(list, int);
		base_plus(nb, (char *)"d", count);
	}
	else if (format[*i] == 'i')
	{
		nb = va_arg(list, int);
		base_plus(nb, (char *)"i", count);
	}
}
