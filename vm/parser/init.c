/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouisy- <alouisy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:41:07 by alouisy-          #+#    #+#             */
/*   Updated: 2018/10/19 13:46:11 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

inline void		init_vm(t_pvm *prms)
{
	t_list		*plst;
	int			i;
	t_process	*tmp;

	//prms->sum_lives = 0;
	//prms->cur_cycle = 0;
	//prms->winner = 0;
	plst = prms->processes;
	i = prms->nb_champ;
	ft_bzero(prms->memory, MEM_SIZE);
	while (--i >= 0)
	{
		tmp = CONTENT(plst);
		tmp->vm_pos = i * (MEM_SIZE / prms->nb_champ);
		tmp->pc = tmp->vm_pos;
		ft_memcpy(prms->memory + tmp->vm_pos, tmp->prog,
			tmp->header.prog_size);
		plst = plst->next;
	}
}

inline void		init_f(t_pvm *prms)
{
	prms->f[0] = &ft_live;
/*	prms->f[1] = &ft_ld;
	prms->f[2] = &ft_st;
	prms->f[3] = &ft_add;
	prms->f[4] = &ft_sub;
	prms->f[5] = &ft_and;
	prms->f[6] = &ft_or;
	prms->f[7] = &ft_xor;
	prms->f[8] = &ft_zjmp;
	prms->f[9] = &ft_ldi;
	prms->f[10] = &ft_sti;
	prms->f[11] = &ft_fork;
	prms->f[12] = &ft_lld;
	prms->f[13] = &ft_lldi;
	prms->f[14] = &ft_lfork;
	prms->f[15] = &ft_aff;*/
}

inline void		init_prms(t_pvm *prms)
{
	prms->dump = -1;
	prms->processes = NULL;
	prms->nb_champ = 0;
	prms->verbose = 0;
	prms->cycle_to_die = CYCLE_TO_DIE;
	prms->total_cycles = 1;
	prms->cycles = 1;
	prms->live = 0;
	prms->last_live = 0;
	prms->nb_checks = 0;
	init_f(prms);
}