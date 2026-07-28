/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:26:46 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/10 11:23:47 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*p_src;
	char	*p_dest;

	i = 0;
	p_src = (char *)src;
	p_dest = (char *)dest;
	if (!p_dest && !p_src)
	{
		return (NULL);
	}
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}

/*int main() {
    char chaine[] = "coucou les cacas";
    char chaine2[20];
    ft_memcpy(chaine2, chaine, 4);
    printf("%s", chaine2);
    return(0);
}*/
