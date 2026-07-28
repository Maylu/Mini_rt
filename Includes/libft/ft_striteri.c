/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:29:47 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/15 15:50:42 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	count;
	int	i;

	i = 0;
	count = ft_strlen(s);
	while (i < count)
	{
		(*f)(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}
