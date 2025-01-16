/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:02:47 by mokoubar          #+#    #+#             */
/*   Updated: 2025/01/15 19:33:40 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	leftovers[(unsigned long)BUFFER_SIZE + 1];

	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (leftovers[0])
		line = ft_strjoin(line, leftovers);
	line = get_line(fd, line, leftovers);
	if (!line)
		return (NULL);
	return (new_line(line, leftovers));
}

char	*get_line(int fd, char *line, char *leftovers)
{
	int	i;

	i = BUFFER_SIZE;
	while (!(ft_strchr(leftovers, '\n')) && i == BUFFER_SIZE)
	{
		i = read(fd, leftovers, BUFFER_SIZE);
		leftovers[i] = '\0';
		if (i <= 0 && !line[0])
			return (free(line), NULL);
		line = ft_strjoin(line, leftovers);
	}
	return (line);
}

char	*new_line(char *line, char *leftovers)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	j = (ft_strlen(line) - i);
	if (j != 0)
		ft_strlcpy(leftovers, line + i, j + 1);
	else
		leftovers[0] = '\0';
	return (ft_substr(line, 0, i + 1));
}

char	*ft_strchr(char *s, int c)
{
	char	*s2;

	if (!s)
		return (NULL);
	if (c < 0 || c > 255)
		return ((char *)s);
	s2 = (char *)s;
	while (*s2 != c && *s2)
		s2++;
	if (*s2 == c)
		return (s2);
	return (NULL);
}
