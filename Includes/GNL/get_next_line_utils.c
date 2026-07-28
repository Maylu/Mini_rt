/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:11:31 by gcamara           #+#    #+#             */
/*   Updated: 2026/07/28 15:46:58 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_printlines(char const *s, char *p, size_t len, unsigned int start)
{
	size_t	i;

	i = 0;
	if (p == (NULL))
		return (NULL);
	while (i < len)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		char_count;
	char		*p;

	if (start >= ft_strlen(s))
	{
		p = malloc(sizeof(char) * 1);
		if (p == NULL)
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	char_count = ft_strlen(&s[start]) + 1;
	if (len < char_count)
	{
		p = malloc(sizeof(char) * len + 1);
		p = ft_printlines(s, p, len, start);
	}
	else
	{
		p = malloc(sizeof(char) * char_count);
		p = ft_printlines(s, p, char_count, start);
	}
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	l;

	l = (unsigned char)c;
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == l)
		{
			return (&str[i]);
		}
		i++;
	}
	if (l == '\0')
	{
		i = ft_strlen(s);
		return (&str[i]);
	}
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	if (size <= dest_len)
		return (src_len + size);
	while (src[i] != '\0' && dest_len + i < size - 1)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		char_count;
	char	*copy;

	char_count = ft_strlen(s1) + ft_strlen (s2);
	copy = malloc(sizeof(char) * char_count + 1);
	if (copy == NULL)
		return (NULL);
	copy[0] = '\0';
	ft_strlcat(copy, s1, ft_strlen(s1) + 1);
	ft_strlcat(copy, s2, char_count + 1);
	return (copy);
}
