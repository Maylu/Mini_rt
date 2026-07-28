/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:55:47 by gcamara           #+#    #+#             */
/*   Updated: 2026/07/23 17:14:17 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		char_count;
	char	*copy;

	char_count = ft_strlen(s1) + ft_strlen (s2);
	copy = malloc(sizeof(char) * char_count + 1);
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s1, ft_strlen(s1)+ 1);
	ft_strlcat(copy, s2, char_count + 1);
	return (copy);
}

/*int main ()
{
  char * s = ft_strjoin("tripouille", "42");  
  printf("%s", s);
  free (s);
}*/
