/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_partial_clr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcugni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:10:01 by zcugni            #+#    #+#             */
/*   Updated: 2018/06/23 13:10:02 by zcugni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

////je devrais pas avoir besoin de ca

void		lst_partial_clr(t_list **lst)
{
	if (lst && *lst)
	{
		if ((*lst)->next)
			lst_partial_clr(&((*lst)->next));
		ft_memdel((void **)lst);
	}
}
