/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:44:29 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/12 17:34:20 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	big_len;
	size_t	little_len;

	i = 0;
	if (!*little)
		return ((char *)big);
	little_len = ft_strlen(little);
	if (len < little_len)
		return (NULL);
	while (big[i] && i < len)
	{
		big_len = 0;
		while ((big[big_len + i])
			&& (big[big_len + i] == little[big_len])
			&& i <= len - little_len)
			big_len++;
		if (big_len == little_len)
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}

/*int main ()
{
        const char *largestring = "abcdefgh";
        const char *smallstring = "abc";
        char *ptr;
        char *ptr2;
        ptr = ft_strnstr(largestring, smallstring, 2);
        ptr2 = strnstr(largestring, smallstring, 2);
        printf("%s\n", largestring);
        printf("%s\n", smallstring);
        printf("%s\n", ptr);
        printf("%s\n", ptr2);
}*/
