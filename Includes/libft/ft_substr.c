/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:34:23 by gcamara           #+#    #+#             */
/*   Updated: 2026/07/23 17:13:56 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

	if (len <= 0)
		return (NULL);
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
/*int main ()
{
  char *s = ft_substr("tripouille", 1, 1);
  printf("%s", s);
  free (s);
}*/
