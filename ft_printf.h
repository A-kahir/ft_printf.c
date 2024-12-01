/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akahir <akahir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:21:32 by akahir            #+#    #+#             */
/*   Updated: 2024/12/01 17:54:36 by akahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
//principle func : 
int		ft_printf(const char *format, ...);
void	ft_handlers(const char *format, int *i, va_list list, int *count);
void	hashtag(const char *format, int *i, va_list list, int *count);
void	space(const char *format, int *i, va_list list, int *count);
void	plus(const char *format, int *i, va_list list, int *count);
//helper func :
size_t	ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
void	ft_base(long long value, const char *format, int *count);
void	base_hashtag(long long value, const char *format, int *count);
void	base_space(long long value, const char *format, int *count);
void	base_plus(long long value, const char *format, int *count);
#endif