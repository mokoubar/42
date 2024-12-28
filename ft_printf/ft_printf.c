/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:21:20 by mokoubar          #+#    #+#             */
/*   Updated: 2024/12/28 16:13:04 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_type(const char *str, va_list args)
{
	int	i;

	i = 0;
	if (*str == '%')
		i += print_char('%');
	else if (*str == 'c')
		i += print_char(va_arg(args, int));
	else if (*str == 's')
		i += print_string(va_arg(args, char *));
	else if (*str == 'p')
		i += print_pointer(va_arg(args, void *));
	else if (*str == 'd' || *str == 'i')
		i += print_integer(va_arg(args, int));
	else if (*str == 'u')
		i += print_unsigned(va_arg(args, unsigned int));
	else if (*str == 'x')
		i += print_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*str == 'X')
		i += print_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
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
			i += print_type(str, args);
		}
		else
			i += print_char(*str);
		str++;
    }
	va_end(args);
	return (i);
}
//#include <stdio.h>
//#include <limits.h>
//int main()
//{
//	ft_printf(" %x ", LONG_MAX);
//	printf(" %x ", LONG_MAX);
//	return 0;
//}