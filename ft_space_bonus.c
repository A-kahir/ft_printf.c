/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:00:13 by akahir            #+#    #+#             */
/*   Updated: 2024/12/01 17:37:32 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	type(const char *format, int *i)
{
	int	j;

	j = *i;
	while (format[*i] == ' ')
	{
		if (ft_strchr("cspdiuxX%", format[j]))
		{
			return (format[j]);
		}
		j++;
	}
	return (0);
}

void	space(const char *format, int *i, va_list list, int *count)
{
	char	j;
	int		nb;

	j = type(format, i);
	if (j == 'c' || j == 's' || j == 'p' || j == 'u'
		|| j == 'x' || j == 'X' || j == '%')
		ft_handlers(format, i, list, count);
	if (j == 'd' && format[*i] == ' ')
	{
		nb = va_arg(list, int);
		base_space(nb, (char *)"d", count);
	}
	else if (j == 'i' && format[*i] == ' ')
	{
		nb = va_arg(list, int);
		base_space(nb, (char *)"i", count);
	}
	i++;
}
