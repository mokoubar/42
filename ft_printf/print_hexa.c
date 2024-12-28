/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:45:16 by mokoubar          #+#    #+#             */
/*   Updated: 2024/12/28 16:12:41 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(unsigned int n, char *str)
{
	int	i;

	i = 0;
	if (n < 16)
		i += print_char(str[n]);
	else if (n >= 16)
	{
		i += print_hexa(n / 16, str);
		i += print_hexa(n % 16, str);		
	}
	return (i);
}
