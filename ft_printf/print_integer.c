/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:43:52 by mokoubar          #+#    #+#             */
/*   Updated: 2024/12/15 18:01:46 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_integer(long	n)
{
	int	i;

	i = 0;
	if (n < 0)
		n *= -1;
	else if (n < 10)
		i += print_char(n + '0');
	else if (n >= 10)
	{
		i += print_integer(n / 10);
		i += print_integer(n % 10);
	}
	return (i);
}