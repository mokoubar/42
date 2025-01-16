/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:25:25 by mokoubar          #+#    #+#             */
/*   Updated: 2025/01/15 18:45:24 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strlcpy(char *dst, char *src, int size)
{
	int	i;
	int	len;

	len = ft_strlen((char *)src);
	i = 0;
	if (size == 0)
		return (len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (len);
}

char	*ft_strdup(char *s)
{
	int		len;
	char	*out;

	len = ft_strlen((char *)s) + 1;
	out = malloc(len * sizeof(char));
	if (!out)
		return (NULL);
	ft_strlcpy(out, s, len + 1);
	free(s);
	return (out);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*out;
	int		s1len;
	int		s2len;

	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	out = malloc((s1len + s2len + 1) * sizeof(char));
	if (!out)
		return (0);
	ft_strlcpy(out, s1, s1len + 1);
	free(s1);
	ft_strlcpy(out + s1len, s2, s2len + 1);
	return (out);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*out;
	int		slen;

	slen = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		return (ft_strdup(s + start));
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	ft_strlcpy(out, s + start, len);
	free(s);
	out[len] = '\0';
	return (out);
}
