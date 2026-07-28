/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:05:28 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/12 15:19:27 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c -= 32;
	}
	return (c);
}

/*int	main()
{
	char a = 'a';
	char b = 'b';
	char c = '-';
	char d = '5';
	char e = ' ';

	printf("%c\n", ft_toupper(a));
	printf("%c\n", ft_toupper(b));
        printf("%c\n", ft_toupper(c));
        printf("%c\n", ft_toupper(d));
        printf("%c\n", ft_toupper(e));
}*/
