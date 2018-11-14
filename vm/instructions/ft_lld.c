/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:27:38 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/11/09 15:21:27 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

/*
** long direct load
*/

static void	aux_verbose(t_pvm *vm, t_process *process, int value)
{
	if ((vm->verbose - 1))
	{
		ft_printf("P% 5d | lld %d r%d\n",
				vm->champions[(int)process->champ_nbr].nbr,
				value,
				vm->param[1]);
		if (vm->verbose == 3)
			print_adv(vm, PC, octal_shift(OCP, 4, 2));
	}
}

int	ft_lld(t_pvm *vm, t_process *process)
{
	int		value;

	value = 0;
	if (check_param(process->opcode, OCP, OP_TAB.nb_param))
	{	
		if (vm->param_type[1] == 1 && vm->param[1] >= 1 && vm->param[1] <= REG_NUMBER)
		{
			if (vm->param_type[0] == IND_CODE)
				value = reverse_bytes(vm, (PC + vm->param[0]), 2);
			else if (vm->param_type[0] == DIR_CODE)
				value = reverse_bytes(vm, (PC + 2), 4);
			REG(vm->param[1]) = value;
			ft_carry(process, REG(vm->param[1]), !(REG(vm->param[1])));
		}
	}
	aux_verbose(vm, process, value);
	PC = (PC + octal_shift(OCP, 4, 2)) % MEM_SIZE;
	return (1);
}
