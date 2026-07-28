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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size <= 0)
		return (src_len);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*int main ()
{
	char chaine[] = "coucou";
        char chaine2[9] = "licorne";
        printf("%s", chaine);
        printf("%s", chaine2);
        size_t i = ft_strlcpy(chaine2, chaine, 3);
        printf("%ld", i);
        printf("%s", chaine2);
        return(0);
}*/
