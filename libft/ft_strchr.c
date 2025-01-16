/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:27:45 by mokoubar          #+#    #+#             */
/*   Updated: 2024/11/19 20:13:03 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*src;

	i = 0;
	src = (char *)s;
	while (src[i])
	{
		if (src[i] == (char)c)
			return (src + i);
		i++;
	}
	if ((char)c == '\0')
		return (&src[i]);
	return (NULL);
}
