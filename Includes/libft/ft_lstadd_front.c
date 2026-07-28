/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:25:55 by gcamara           #+#    #+#             */
/*   Updated: 2025/11/29 17:18:14 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"


void ft_lstadd_front(t_list **lst, t_list *new)
{
	
	//*lst = new;
	//new-> content = content;
	new->next = *lst;
	*lst = new;
}
