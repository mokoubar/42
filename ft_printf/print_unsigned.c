/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:00:34 by mokoubar          #+#    #+#             */
/*   Updated: 2024/12/28 12:11:42 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 10)
		i += print_char(n + '0');
	else if (n >= 10)
	{
		i += print_integer(n / 10);
		i += print_integer(n % 10);
	}
	return (i);
}