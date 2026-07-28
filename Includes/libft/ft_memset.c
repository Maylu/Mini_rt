/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:43:27 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/08 18:01:38 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)dest;
	while (i < count)
	{
		str[i] = c;
		i++;
	}
	return (dest);
}

/*int main()
{
    int n = 5;
    int arr[] = { 10, 5, 6, 7, 8 };
    ft_memset(arr, 0, 8);
    printf("Array after memset()\n");
    for (int i=0; i<n; i++)
      printf("%d ", arr[i]);
    return 0;
}*/
