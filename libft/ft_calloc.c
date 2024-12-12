/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:40:15 by mokoubar          #+#    #+#             */
/*   Updated: 2024/11/16 16:41:42 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*t;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	t = malloc(count * size);
	if (!t)
		return (NULL);
	ft_bzero(t, count * size);
	return (t);
}
