/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:27:05 by akahir            #+#    #+#             */
/*   Updated: 2024/12/04 11:37:59 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	bonus_part(const char *format, int *i, va_list list, int *count)
{
	while (format[*i + 1] == '#' || format[*i + 1] == ' '
		|| format[*i + 1] == '+')
	{
		(*i)++;
	}
	while (format[*i + 1] >= '0' && format[*i + 1] <= '9')
	{
		if (format[*i + 1] >= '0' && format[*i + 1] <= '9')
			*count += write(1, " ", 1);
		(*i)++;
	}
	if (ft_strchr("cspdiuxX%", format[*i + 1]))
	{
		if (format[*i] == '#')
			hashtag(format, i, list, count);
		else if (format[*i] == ' ')
			space(format, i, list, count);
		else if (format[*i] == '+')
			plus(format, i, list, count);
	}
	(*i)++;
}

void	handle_format(const char *format, int *i, va_list list, int *count)
{
	if (ft_strchr("cspdiuxX%", format[*i + 1]))
	{
		ft_handlers(format, i, list, count);
		(*i)++;
	}
	else
		bonus_part(format, i, list, count);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		count;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(list, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			handle_format(format, &i, list, &count);
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(list);
	return (count);
}
