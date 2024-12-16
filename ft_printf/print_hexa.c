/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:45:16 by mokoubar          #+#    #+#             */
/*   Updated: 2024/12/15 16:49:16 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(long n, char *str)
{
	int	i;

	i = 0;
	if (n == 0)
		i += print_char('0');	
	else if (n < 16)
		i += print_char(str[n]);
	else if (n >= 16)
	{
		i += print_hexa(n / 16, str);
		i += print_hexa(n % 16, str);		
	}
}
