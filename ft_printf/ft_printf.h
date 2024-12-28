/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:26:40 by mokoubar          #+#    #+#             */
/*   Updated: 2024/12/28 16:12:49 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *str, ...);
int		print_char(char c);
int		print_string(char *str);
int		print_pointer(void *n);
int		print_integer(int	n);
int		print_unsigned(unsigned int n);
int		print_hexa(unsigned int n, char *str);

#endif
