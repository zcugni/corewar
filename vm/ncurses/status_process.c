/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:47:47 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/30 17:14:12 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

/*
** print information about processes in right panel
*/

int registre_status(t_pvm *vm, int i)
{
	int j;
	t_process	*process;
	

	process = PROCESS(vm->processes);	
	j = 0;
	while (j < REG_NUMBER)
	{
		mvwprintw(vm->nc.wright, i++, 0,
			"| reg %2d | %10d |", j, process->r[j]);
		j++;
	}
	return (i);
}

int	param_status(t_pvm *vm, int i)
{
	t_process	*process;

	process = PROCESS(vm->processes);
	mvwprintw(vm->nc.wright, i++, 0,
			"| param 0 | param 1 | param 2 |");
	mvwprintw(vm->nc.wright, i++, 0,
			"| %7d | %7d | %7d |",
			process->param[0],
			process->param[1],
			process->param[2]);
	mvwprintw(vm->nc.wright, i++, 0,
			"| type0 | type1 | type2 |");
	mvwprintw(vm->nc.wright, i++, 0,
			"| %5d | %5d | %5d |",
			process->param_type[0],
			process->param_type[1],
			process->param_type[2]);
	return (i);
}

void		status_process(t_pvm *vm, int i)
{
	t_list		*node;
	t_process	*process;

	mvwprintw(vm->nc.wright, i++, 0,
		"| pid   | owner | pc    | pc2   | opcode | carry | live  | exe  |");
	mvwprintw(vm->nc.wright, i++, 0,
		"._______._______._______._______.________._______._______.______.");
	node = vm->processes;
	while (node)
	{
		process = PROCESS(node);
		mvwprintw(vm->nc.wright, i++, 0,
				"| %5d | %5d | %5d | %5d | %6d | %5d | %5d | %4d |",
				process->pid,
				process->champ_nbr,
				process->pc,
				process->pc2,
				process->opcode,
				process->carry,
				process->cycles_wo_live,
				process->cycle_bf_exe);
		node = node->next;
	}
	if (vm->processes)
	{
		i = param_status(vm, i + 1);
		registre_status(vm, i + 1);
	}
}