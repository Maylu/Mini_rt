/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:15:27 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/12 11:20:53 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
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
	
	printf("%d\n", ft_isdigit(a));
	printf("%d\n", ft_isdigit(b));
        printf("%d\n", ft_isdigit(c));
        printf("%d\n", ft_isdigit(d));
        printf("%d\n", ft_isdigit(e));
}*/
