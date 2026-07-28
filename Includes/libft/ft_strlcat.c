/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:32:28 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/12 14:17:26 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int main ()
{
	char chaine[] = "coucou";
        char chaine2[9] = "licorne";
        printf("%s", chaine);
        printf("%s", chaine2);
        size_t i = ft_strlcat(chaine2, chaine, 9);
        printf("%ld", i);
        printf("%s", chaine2);
        return(0);
}*/
