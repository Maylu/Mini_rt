/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:28:16 by gcamara           #+#    #+#             */
/*   Updated: 2026/07/23 17:04:50 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		str_count;
	char	l;
	char	*str;

	l = (unsigned char)c;
	str = (char *)s;
	str_count = ft_strlen(str);
	while (str_count >= 0)
	{
		if (str[str_count] == l)
		{
			return (&str[str_count]);
		}
		str_count--;
	}
	return (NULL);
}

/*int main ()
{
        char chaine[] = "coucou les licornes";
        printf("%s", ft_strrchr(chaine, 'c'));
        return(0);
}*/
