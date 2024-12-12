/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoubar <mokoubar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:00:48 by mokoubar          #+#    #+#             */
/*   Updated: 2024/11/18 12:27:09 by mokoubar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countword(char const *s, char c)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	j = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] == c)
			w = 0;
		else if (w == 0)
		{
			w = 1;
			j++;
		}
		i++;
	}
	return (j);
}

static void	free_all(char **result)
{
	char	**current;

	current = result;
	while (*current)
	{
		free(*current);
		current++;
	}
	free(result);
}

static void	allocate(char **result, char const *s, char c)
{
	char		**arr;
	char const	*tmp;

	arr = result;
	tmp = s;
	while (*s)
	{
		while (*s == c)
			s++;
		tmp = s;
		while (*tmp && *tmp != c)
			tmp++;
		if (tmp > s)
		{
			*arr = ft_substr(s, 0, tmp - s);
			if (!*arr)
			{
				free_all(result);
				return ;
			}
			s = tmp;
			arr++;
		}
	}
	*arr = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		size;

	if (!s)
		return (NULL);
	size = countword(s, c);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	allocate(result, s, c);
	return (result);
}
