/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pop_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcugni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 20:28:20 by zcugni            #+#    #+#             */
/*   Updated: 2018/11/06 20:28:22 by zcugni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lst_pop_at(t_list **lst, void *p)
{
	t_list *current_elem;
	t_list *prev_elem;

	current_elem = *lst;
	prev_elem = NULL;
	while (current_elem)
	{
		if (current_elem->content == p)
		{
			if (prev_elem)
				prev_elem->next = current_elem->next;
			else
				*lst = current_elem->next;
			current_elem->next = NULL;
			return (current_elem);
		}
		prev_elem = current_elem;
		current_elem = current_elem->next;
	}
	return (NULL);
}
