/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtag_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:25:23 by akahir            #+#    #+#             */
/*   Updated: 2024/12/03 19:36:57 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	type(const char *format, int *i)
{
	int	j;

	j = *i;
	while (format[*i] == '#')
	{
		if (ft_strchr("cspdiuxX%", format[j]))
		{
			return (format[j]);
		}
		j++;
	}
	return (0);
}

void	hashtag(const char *format, int *i, va_list list, int *count)
{
	char			j;
	unsigned int	x;

	j = type(format, i);
	if (j == 'c' || j == 's' || j == 'd' || j == 'i' || j == 'u' || j == '%')
		ft_handlers(format, i, list, count);
	if (j == 'p' && format[*i] == '#')
	{
		ft_handlers(format, i, list, count);
	}
	else if (j == 'x' && format[*i] == '#')
	{
		x = va_arg(list, unsigned int);
		base_hashtag(x, (char *)"x", count);
	}
	else if (j == 'X' && format[*i] == '#')
	{
		x = va_arg(list, unsigned int);
		base_hashtag(x, (char *)"X", count);
	}
}
