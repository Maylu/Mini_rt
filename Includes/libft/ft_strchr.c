/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:53:43 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/10 12:13:03 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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

/*int main ()
{
	char chaine[] = "coucou les licornes";
	printf("%s", ft_strchr(chaine, 'a'));
	return(0);
}*/
