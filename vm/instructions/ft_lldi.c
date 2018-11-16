/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:46:23 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/11/16 18:30:01 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

/*
** indirect load
*/

static void	aux_verbose(t_pvm *vm, t_list *node, int val1, int val2)
{
	t_process	*process;

	process = get_process(node);
	if ((vm->verbose == 3))
	{
		ft_printf("P% 5d | lldi %d %d r%d\n",
				node->content_size,
				val1,
				val2,
				vm->param[2]);
		ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
				val1,
				val2,
				(val1 + val2),
				PC + val1 + val2);
	}
}

int			ft_lldi(t_pvm *vm, t_list *node)
{
	int			val1;
	int			val2;
	t_process	*process;

	process = get_process(node);
	val1 = 0;
	val2 = 0;
	if (check_param(process->opcode, OCP, OP_TAB.nb_param))
	{
		if (vm->param_type[2] == 1
			&& vm->param[2] >= 1 && vm->param[2] <= REG_NUMBER
			&& get_prm_value(vm, process, 0, &val1)
			&& get_prm_value(vm, process, 1, &val2))
		{
			REG(vm->param[2]) = reverse_bytes(vm, PC + val1 + val2, 4);
			ft_carry(process, REG(vm->param[2]), !(REG(vm->param[2])));
			aux_verbose(vm, node, val1, val2);
		}
	}
	if (vm->verbose == 3)
		print_adv(vm, PC, octal_shift(OCP, 2, 3));
	PC = (PC + octal_shift(OCP, 2, 3)) % MEM_SIZE;
	return (1);
}
