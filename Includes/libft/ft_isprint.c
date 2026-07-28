/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:57:07 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/12 12:18:16 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
	char e = '	';
	
	printf("%d\n", ft_isprint(a));
	printf("%d\n", ft_isprint(b));
        printf("%d\n", ft_isprint(c));
        printf("%d\n", ft_isprint(d));
        printf("%d\n", ft_isprint(e));
}*/
