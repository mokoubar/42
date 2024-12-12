/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:21:20 by mokoubar          #+#    #+#             */
/*   Updated: 2024/12/10 09:51:31 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_type(char c, void *arg)
{
	int	j;

	j = 0;
	if (c == '%')
		j =+ print_char(c);
	else if (c == 'c')
		j += print_char((char)arg);
	else if (c == 's')
		j += print_string((char *)arg);
	else if (c == 'p')
		j += print_pointer();
	else if (c == 'd')
		j += print_integer((int)arg);
	else if (c == 'i')
		j += print_integer((int)arg);
	else if (c == 'u')
		j += print_unsigneddecimal((unsigned int)arg);
	else if (c == 'x')
		j += print_lowercasehexadecimal();
	else if (c == 'X')
		j += print_uppercasehexadecimal();
	return (j);
}

int	ft_printf(const char * str, ...)
{
    int i;
	int	j;
    va_list args;

    i = 0;
	j = 0;
    va_start(args, str);
    while (str[i])
    {
		if (str[i] == "%")
			j += print_type(str[i], va_arg(args, void *));
		else
		{
			write(1, &str[i], 1);
			j++;
		}
		i++;
    }
	va_end(args);
	return (j);
}
