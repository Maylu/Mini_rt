/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:44:37 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/19 13:45:56 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_dest(char const *s, char c)
{
	int	i;
	int	count;
	int	is_world;

	count = 1;
	i = 0;
	is_world = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			is_world = 1;
		if (s[i] != c)
		{
			if (is_world == 1)
			{
				count++;
				is_world = 0;
			}
		}
		i++;
	}
	return (count);
}

int	count_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_free_split(int nb, char **dest)
{
	while (nb >= 0)
	{
		free (dest[nb]);
		nb--;
	}
	free (dest);
}

char	**split_lines(char **dest, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			dest[j] = ft_substr(s, i, count_len(s + i, c));
			if (!dest[j])
			{
				ft_free_split(j, dest);
				return (NULL);
			}
			while (s[i] != c && s[i] != '\0')
				i++;
			j++;
		}
		if (s[i])
			i++;
	}
	dest[j] = (NULL);
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**dest;

	count = count_dest(s, c);
	dest = malloc(sizeof(char *) * count);
	if (dest == NULL)
		return (NULL);
	dest = split_lines(dest, s, c);
	return (dest);
}
