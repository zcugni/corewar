/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:16:15 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/11/09 15:21:14 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void	aux_verbose(t_pvm *vm, t_process *process)
{
	if (vm->verbose == 2)
	{
		ft_printf("P% 5d | live %d\n",
				(CHAMPION(process->champ))->nbr,
				vm->param[0]);
	}
	else if (vm->verbose == 3)
		print_adv(vm, process->pc, 5);
}

int	ft_live(t_pvm *vm, t_process *process)
{
	t_list	*node;

	if (!(process->state % 2))
		process->state += 1;
	vm->sum_lives++;
	vm->param[0] = reverse_bytes(vm, process->pc + 1, 4);
	if ((node = ft_lstfindchamp(vm->champions, vm->param[0])))
	{
		(CHAMPION(node))->nb_live++;
		(CHAMPION(node))->l_live = vm->total_cycles;
		vm->last_live = vm->total_cycles;
	}
	aux_verbose(vm, process);
	process->pc += 5;
	process->pc %= MEM_SIZE;
	return (1);
}
