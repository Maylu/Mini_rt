/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_charset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:42:06 by gcamara           #+#    #+#             */
/*   Updated: 2026/08/30 16:48:37 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	count_dest_charset(char const *s, char *c)
{
	int	i;
	int	count;
	int	is_word;

	count = 1;
	i = 0;
	is_word = 1;
	while (s[i] != '\0')
	{
		if (ft_strspn(s[i], c) == 1)
			is_word = 1;
		if (ft_strspn(s[i], c) == 0)
		{
			if (is_word == 1)
			{
				count++;
				is_word = 0;
			}
		}
		i++;
	}
	return (count);
}

int	count_len_charset(char const *s, char *c)
{
	int	i;

	i = 0;
	while ((ft_strspn(s[i], c) == 0) && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_free_split_charset(int nb, char **dest)
{
	while (nb >= 0)
	{
		free (dest[nb]);
		nb--;
	}
	free (dest);
}

char	**split_lines_charset(char **dest, char const *s, char *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (ft_strspn(s[i], c) == 0)
		{
			dest[j] = ft_substr(s, i, count_len_charset(s + i, c));
			if (!dest[j])
			{
				ft_free_split_charset(j, dest);
				return (NULL);
			}
			while ((ft_strspn(s[i], c) == 0) && s[i] != '\0')
				i++;
			j++;
		}
		if (s[i])
			i++;
	}
	dest[j] = (NULL);
	return (dest);
}

char	**ft_split_charset(char const *s, char *c)
{
	int		count;
	char	**dest;

	count = count_dest_charset(s, c);
	dest = malloc(sizeof(char *) * count);
	if (dest == NULL)
		return (NULL);
	dest = split_lines_charset(dest, s, c);
	return (dest);
}
