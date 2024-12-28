/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:57:52 by mokoubar          #+#    #+#             */
/*   Updated: 2024/12/28 12:21:55 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_string(char *str)
{
    int i;

    i = 0;
	if (str == NULL)
    	return (write(1, "(null)", 6));
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}