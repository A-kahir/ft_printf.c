/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <aymanekahir036@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:21:32 by akahir            #+#    #+#             */
/*   Updated: 2024/11/25 22:33:22 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF
#define LIBFT_PRINTF

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
#       include <stdio.h>
//principle func : 
int		ft_printf(const char *format, ...);
void	ft_handlers(const char *format, int i, va_list list, int *count);
//helper func :
size_t	ft_strlen(char *str);
void	ft_base(unsigned long value,const char *format, const char *base, int *count);
#endif