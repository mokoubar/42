/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:00:07 by mokoubar          #+#    #+#             */
/*   Updated: 2024/12/16 11:15:22 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_pointer(long n)
{
	int	i;

	i = 0;
	i += print_char('0');
	i += print_char('x');
	i += print_hexa(n, "0123456789abcdef");
	return (i);
}
