/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:26:54 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/12 11:36:23 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57)
		|| (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}

/*int	main()
{
	char a = 'a';
	char b = 'B';
	char c = '-';
	char d = '5';
	char e = ' ';
	
	printf("%d\n", ft_isalnum(a));
	printf("%d\n", ft_isalnum(b));
        printf("%d\n", ft_isalnum(c));
        printf("%d\n", ft_isalnum(d));
        printf("%d\n", ft_isalnum(e));
}*/
