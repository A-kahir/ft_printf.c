/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:27:05 by akahir            #+#    #+#             */
/*   Updated: 2024/12/08 17:32:31 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft(char format, int *hashtag_flag, int *plus_flag, int *space_flag)
{
	if (format == '#')
		*hashtag_flag = 1;
	if (format == '+')
		*plus_flag = 1;
	if (format == ' ')
		*space_flag = 1;
}

static void	bonus_part(const char *format, int *i, va_list list, int *count)
{
	int	hashtag_flag;
	int	plus_flag;
	int	space_flag;

	hashtag_flag = 0;
	plus_flag = 0;
	space_flag = 0;
	while (format[*i + 1] == '#' || format[*i + 1] == ' '
		|| format[*i + 1] == '+')
	{
		ft(format[*i + 1], &hashtag_flag, &plus_flag, &space_flag);
		(*i)++;
	}
	while (format[*i + 1] == ' ')
		(*i)++;
	if (ft_strchr("cspdiuxX%", format[*i + 1]))
	{
		(*i)++;
		if (hashtag_flag)
			hashtag(format, i, list, count);
		if (plus_flag)
			plus(format, i, list, count);
		if (space_flag)
			space(format, i, list, count);
	}
}

void	handle_format(const char *format, int *i, va_list list, int *count)
{
	if (format[*i] == '%' && format[*i + 1] == '\0')
	{
		return ;
	}
	if ((format[*i] == '%') && ft_strchr("cspdiuxX%", format[*i + 1]))
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
