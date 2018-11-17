/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:03:28 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/11/17 15:29:43 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

/*
** aritmetical addition
*/

static void	aux_verbose(t_pvm *vm, t_list *node)
{
	if (vm->verbose == 3)
	{
		ft_printf("P% 5d | add r%d r%d r%d\n",
				node->content_size,
				vm->param[0],
				vm->param[1],
				vm->param[2]);
	}
}

int			ft_add(t_pvm *vm, t_list *node)
{
	int			i;
	int			error;
	t_process	*process;

	process = get_process(node);
	i = -1;
	error = 0;
	if (check_param(process->opcode, vm->ocp, OP_TAB.nb_param))
	{
		while (++i < 3)
			if (vm->param[i] < 1 || vm->param[i] > REG_NUMBER)
				error = 1;
		if (!error)
		{
			REG(vm->param[2]) = REG(vm->param[0]) + REG(vm->param[1]);
			ft_carry(process, REG(vm->param[2]), !(REG(vm->param[2])));
			aux_verbose(vm, node);
		}
	}
	update_pc(vm, process, 4, 3);
	return (1);
}
