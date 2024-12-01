/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:45:22 by akahir            #+#    #+#             */
/*   Updated: 2024/12/01 17:37:05 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	cantinue2(const char *format, int *i, va_list list, int *count)
{
	unsigned int	y;

	if (format[*i + 1] == 'u')
	{
		y = va_arg(list, unsigned int);
		ft_base(y, (char *)"u", count);
	}
	if (format[*i + 1] == 'x')
	{
		y = va_arg(list, unsigned int);
		ft_base(y, (char *)"x", count);
	}
	else if (format[*i + 1] == 'X')
	{
		y = va_arg(list, unsigned int);
		ft_base(y, (char *)"X", count);
	}
	else if (format[*i + 1] == '%')
	{
		*count += write(1, "%", 1);
	}
}

static void	cantinue1(const char *format, int *i, va_list list, int *count)
{
	void			*ptr;
	int				nb;

	if (format[*i + 1] == 'p')
	{
		ptr = va_arg(list, void *);
		if (ptr == NULL)
		{
			*count += write(1, "0x0", 3);
			return ;
		}
		ft_base((unsigned long)ptr, (char *)"p", count);
	}
	else if (format[*i + 1] == 'd')
	{
		nb = va_arg(list, int);
		ft_base(nb, (char *)"d", count);
	}
	else if (format[*i + 1] == 'i')
	{
		nb = va_arg(list, int);
		ft_base(nb, (char *)"i", count);
	}
	cantinue2(format, i, list, count);
}

void	ft_handlers(const char *format, int *i, va_list list, int *count)
{
	char	c;
	char	*str;

	if (format[*i + 1] == 'c')
	{
		c = (char)va_arg(list, int);
		*count += write(1, &c, 1);
	}
	else if (format[*i + 1] == 's')
	{
		str = va_arg(list, char *);
		if (str == NULL)
		{
			*count += write(1, "(null)", 6);
			return ;
		}
		*count += write(1, str, ft_strlen(str));
	}
	cantinue1(format, i, list, count);
}
