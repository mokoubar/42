/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:48:46 by mokoubar          #+#    #+#             */
/*   Updated: 2024/11/19 20:14:17 by moel-hib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
        int             i;
        char    *src;

        i = 0;
        src = (char *)s;
        while (src[i])
                i++;
        while (0 <= i)
        {
                if ((unsigned char)src[i] == (unsigned char)c)
                        return (src + i);
                i--;
        }
        if (c == '\0')
                return (src + i);
        return (NULL);
}

