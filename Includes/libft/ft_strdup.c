/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:40:55 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/04 15:55:30 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		src_len;
	char	*dest;

	i = 0;
	src_len = ft_strlen(s) + 1;
	dest = malloc(sizeof(char) * src_len);
	if (dest == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main()
{
	char chaine [] = "coucou";
	char *copie = ft_strdup (chaine);
	printf("%s", copie);
	free(copie);
}*/
