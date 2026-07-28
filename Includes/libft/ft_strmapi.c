/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:51:58 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/15 14:53:03 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*char test(unsigned int i, char c)
{
	return (i + c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		count;
	int		i;
	char	*p;

	i = 0;
	count = ft_strlen(s) + 1;
	if (!s)
	{
		p = malloc(sizeof(char) * 1);
		p[0] = '\0';
		return (p);
	}
	p = malloc(sizeof(char) * count);
	if (p == NULL)
		return (NULL);
	while (i < count - 1)
	{
		p[i] = (*f)(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}

/*int main()
{
    char * s = ft_strmapi("1234", test);
    printf("%s", s);
}*/
