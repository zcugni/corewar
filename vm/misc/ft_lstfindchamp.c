/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindchamp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:34:01 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/26 15:34:03 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

int ft_findchamp(t_pvm *vm, int nbr)
{
	int i;

	i = 0;
	while (i < vm->nb_champ)
	{
		if (vm->champions[i].nbr == nbr)
			return (i);
		i++;
	}
	return (-1);
}
