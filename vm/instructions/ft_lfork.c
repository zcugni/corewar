/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:46:28 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/31 17:34:31 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

/*
** long fork
*/

void	ft_lfork(t_pvm *pvm, t_process *process)
{
	int			value;
	int			new_pc;
	t_list		*node;

	(void)node;
	value = (short int)process->param[0];
	new_pc = (process->pc + value) % MEM_SIZE;
	if (new_pc < 0)
		new_pc = (new_pc + MEM_SIZE) % MEM_SIZE;
//		new_pc = (MEM_SIZE + process->pc - ABS(value)) % MEM_SIZE;
	node = ft_lstnew2(process, sizeof(t_process));
	new_process_init(pvm, process, (PROCESS(node)), new_pc);
	ft_lstadd(&pvm->processes, node);
	if (!(pvm->nc.ncurses) && pvm->verbose)
	{
		ft_printf("P% 5d | lfork %d (%d)\n", process->champ_nbr, value, (process->pc + value));
	}
	pvm->nc.clear = 1;
}
