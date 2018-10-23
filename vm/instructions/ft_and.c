/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:11:05 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/23 17:23:39 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

/*
** loqical and
*/

void	ft_and(UNUSED t_pvm *pvm, t_process *process)
{
	int		value;

	value = (process->param[0] & process->param[1]) % IDX_MOD;
	process->r[process->param[2]] = value;
	if (value == 0)
		process->carry = 1;
	else
		process->carry = 0;
}

/*void	ft_and(UNUSED t_pvm *pvm, t_process *process)
{	
	process->param[2] = (process->param[0] & process->param[1]) % IDX_MOD;
	if (process->param[2] == 0)
		process->carry = 1;
	else
		process->carry = 0;
}*/
