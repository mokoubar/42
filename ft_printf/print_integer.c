/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:43:52 by mokoubar          #+#    #+#             */
/*   Updated: 2025/01/04 11:22:38 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += print_string("-2147483648");
		return (i);
	}
	if (n < 0)
	{
		i += print_char('-');
		n *= -1;
	}
	if (n < 10)
		i += print_char(n + '0');
	else if (n >= 10)
	{
		i += print_integer(n / 10);
		i += print_integer(n % 10);
	}
	return (i);
}
