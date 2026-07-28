/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:53:21 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/12 18:16:46 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	negative;
	int	result;

	i = 0;
	negative = 0;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			negative++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (negative % 2 != 0)
		result *= -1;
	return (result);
}
/*int main ()
{
        printf("%d\n", ft_atoi(""));
        printf("%d\n", ft_atoi("-42"));
        printf("%d\n", ft_atoi("69878"));
        printf("%d\n", ft_atoi("asc51"));
        return(0);
}*/
