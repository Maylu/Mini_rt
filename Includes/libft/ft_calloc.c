/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:50:35 by gcamara           #+#    #+#             */
/*   Updated: 2026/07/23 17:13:05 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	memb_count;
	char	*p;

	memb_count = nmemb * size;
	i = 0;
	if (size <= 0 && nmemb <= 0)
	{
		return (NULL);
	}
	if (size && (memb_count / size) < nmemb)
	{
		return (NULL);
	}
	p = malloc(memb_count);
	if (p == NULL)
	{
		return (NULL);
	}
	while (i < memb_count)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
/*int main() {

    int *ptr = (int *)ft_calloc(5, sizeof(int));
    
    if (ptr == NULL) {
        exit(0);
    }
    for (int i = 0; i < 5; i++)
        printf("%d ", ptr[i]);
    return 0;
}*/
