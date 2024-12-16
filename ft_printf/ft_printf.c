/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:21:20 by mokoubar          #+#    #+#             */
/*   Updated: 2024/12/16 12:02:05 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_type(const char *str, void *arg)
{
	int	i;

	i = 0;
	if (*str == '%')
		i =+ print_char('%');
	else if (*str == 'c')
		i += print_char((long)arg);
	else if (*str == 's')
		i += print_string((char *)arg);
	else if (*str == 'p')
		i += print_pointer((long)arg);
	else if (*str == 'd' || *str == 'i' || *str == 'u')
		i += print_integer((long)arg);
	else if (*str == 'x')
		i += print_hexa((long)arg, "0123456789abcdef");
	else if (*str == 'X')
		i += print_hexa((long)arg, "0123456789ABCDEF");
	return (i);
}

int	ft_printf(const char * str, ...)
{
	int	i;
    va_list args;

	i = 0;
    va_start(args, str);
    while (*str)
    {
		if (*str == '%')
		{
			str++;
			i += print_type(str, va_arg(args, void *));
		}
		else
			i += print_char(*str);
		str++;
    }
	va_end(args);
	return (i);
}
