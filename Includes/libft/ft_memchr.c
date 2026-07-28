/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:24:12 by gcamara           #+#    #+#             */
/*   Updated: 2026/07/23 17:11:18 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_str;
	unsigned char	l;

	i = 0;
	p_str = (unsigned char *)str;
	l = (unsigned char) c;
	while (i < n)
	{
		if (p_str[i] == l)
		{
			return ((void *)(p_str + i));
		}
		i++;
	}
	return (NULL);
}
/*int main ()
{
	char chaine[] = "coucou les licornes";
	printf("%s", ((char *)ft_memchr(chaine, 'l', 19)));
	return(0);
}*/
