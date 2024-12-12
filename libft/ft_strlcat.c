/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:42:09 by mokoubar          #+#    #+#             */
/*   Updated: 2024/11/16 19:22:25 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;

	if (dst == NULL || src == NULL)
		if (size == 0)
			return (0);
	i = 0;
	d = ft_strlen(dst);
	s = ft_strlen((char *)src);
	if (d >= size)
		return (size + s);
	while (src[i] && (d + i) < size - 1)
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (s + d);
}
