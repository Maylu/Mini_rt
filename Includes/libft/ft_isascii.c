/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:41:52 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/12 11:51:00 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
	char e = '€';
	
	printf("%d\n", ft_isascii(a));
	printf("%d\n", ft_isascii(b));
        printf("%d\n", ft_isascii(c));
        printf("%d\n", ft_isascii(d));
        printf("%d\n", ft_isascii(e));
}*/
