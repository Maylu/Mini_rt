/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:46:48 by gcamara           #+#    #+#             */
/*   Updated: 2026/07/23 17:21:25 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char const *s1, char *dest, size_t begin, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		dest[i] = s1[i + begin];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		begin;
	size_t		end;
	size_t		count;
	char		*dest;

	begin = 0;
	end = ft_strlen(s1);
	while (s1[begin] != '\0' && ft_strchr(set, (int)s1[begin]))
		begin++;
	if (s1[begin] == '\0')
	{
		dest = malloc(sizeof(char) * 1);
		if (dest == NULL)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	while (end > 0 && ft_strrchr(set, (int)s1[end - 1]))
		end--;
	count = end - begin;
	dest = malloc(sizeof(char) * count + 1);
	if (dest == NULL)
		return (NULL);
	dest = ft_strcpy(s1, dest, begin, count);
	return (dest);
}
