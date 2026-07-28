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

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c += 32;
	}
	return (c);
}

/*int	main()
{
	char a = 'A';
	char b = 'B';
	char c = '-';
	char d = '5';
	char e = ' ';

	printf("%c\n", ft_tolower(a));
	printf("%c\n", ft_tolower(b));
        printf("%c\n", ft_tolower(c));
        printf("%c\n", ft_tolower(d));
        printf("%c\n", ft_tolower(e));
}*/
