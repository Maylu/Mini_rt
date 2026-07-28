/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:22:52 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/10 10:24:14 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*c;

	i = 0;
	c = s;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}

/*int main() {
    char chaine [] = "coucou les cacas";
    bzero(chaine, 5);
}*/
