/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:48:18 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/12 11:09:56 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
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
	
	printf("%d\n", isalpha(a));
	printf("%d\n", isalpha(b));
        printf("%d\n", isalpha(c));
        printf("%d\n", isalpha(d));
        printf("%d\n", isalpha(e));
}*/
