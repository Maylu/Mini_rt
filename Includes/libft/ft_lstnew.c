/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamara <gcamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:53:10 by gcamara           #+#    #+#             */
/*   Updated: 2026/07/24 16:17:12 by gcamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *head = NULL;

	head = malloc(sizeof(t_list));
		if(head == NULL)
			return(NULL);
	head-> content = content;
	head-> next = NULL;

	return(head);
}
