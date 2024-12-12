/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:00:21 by mokoubar          #+#    #+#             */
/*   Updated: 2024/11/19 17:38:22 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	ft_putnbr(long nb, char *str, int i)
{
	if (nb < 10)
	{
		str[i++] = nb + '0';
		return (i);
	}
	i = ft_putnbr(nb / 10, str, i);
	str[i++] = nb % 10 + '0';
	return (i);
}

char	*ft_itoa(int nm)
{
	int		i;
	char	*str;
	long	n;

	n = nm;
	i = 0;
	str = malloc(count(n) + 1);
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	i = ft_putnbr(n, str, i);
	str[i] = '\0';
	return (str);
}
