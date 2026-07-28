/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:20:52 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/29 18:59:14 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;
	if (lst == NULL)
		return(NULL);
	last = lst;
	while (last->next != NULL)
	{
		last = last->next;
	}
	return(last);
}
