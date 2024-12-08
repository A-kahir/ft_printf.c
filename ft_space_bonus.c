/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:00:13 by akahir            #+#    #+#             */
/*   Updated: 2024/12/08 19:09:28 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	space(const char *format, int *i, va_list list, int *count)
{
	char *str;
	int		nb;

	if (format[*i] == 'c' || format[*i] == 'p' || format[*i] == 'u'
		|| format[*i] == 'x' || format[*i] == 'X' || format[*i] == '%')
		ft_handlers(format, i, list, count);
	if (format[*i] == 's')
	{
		str = va_arg(list, char *);
		if (str == NULL)
		{
			*count += write(1, "(null)", 6);
			return ;
		}
		*count += write(1, str, ft_strlen(str));
	}
	if (format[*i] == 'd')
	{
		nb = va_arg(list, int);
		base_space(nb, (char *)"d", count);
	}
	else if (format[*i] == 'i')
	{
		nb = va_arg(list, int);
		base_space(nb, (char *)"i", count);
	}
	i++;
}
