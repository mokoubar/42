/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:00:07 by mokoubar          #+#    #+#             */
/*   Updated: 2025/01/04 11:22:54 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexa(unsigned long n, char *str)
{
	int	i;

	i = 0;
	if (n < 16)
		i += print_char(str[n]);
	else if (n >= 16)
	{
		i += hexa(n / 16, str);
		i += hexa(n % 16, str);
	}
	return (i);
}

int	print_pointer(void *n)
{
	int	i;

	i = 0;
	if (!n)
		return (print_string("(nil)"));
	i += print_char('0');
	i += print_char('x');
	i += hexa((unsigned long)n, "0123456789abcdef");
	return (i);
}
