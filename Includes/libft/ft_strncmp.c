/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:27:34 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/12 15:39:47 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while ((p1[i] != '\0') && (p1[i] == p2[i]) && (i < n))
	{
		i++;
	}
	while (i >= n)
	{
		return (0);
	}
	return (p1[i] - p2[i]);
}

/*int main()
{
	char chaine[] = "coucou";
        char chaine2[] = "coucaa";
	printf("%d", ft_strncmp(chaine, chaine2, 6));
	return (0);
}*/
