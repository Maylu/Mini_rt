/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:54:35 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/15 20:07:44 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strint(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		count += 1;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	num;
	long	end;
	char	*p;

	num = (long)n;
	end = (ft_strint(n) + 1) - 1;
	p = malloc(sizeof(char) * (ft_strint(n) + 1));
	if (p == NULL)
		return (NULL);
	if (num == 0)
		p[0] = '0';
	if (num < 0)
	{
		p[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		p[end - 1] = (num % 10) + '0';
		num = num / 10;
		end--;
	}
	p[(ft_strint(n) + 1) - 1] = '\0';
	return (p);
}
/*int main()
{
    char *s;
    //char * s = ft_strmapi("1234", addOne);
    printf("%s", ft_itoa(-10000050));
}*/
