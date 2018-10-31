/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:47:47 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/30 18:11:52 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void		init_ncurses(t_pvm *vm)
{
	initscr();
	keypad(stdscr, TRUE);
	init_colors();
	intro_champions(vm);
	clear();
	vm->nc.wleft = subwin(stdscr, LINES, 15 * COLS / 20, 0, 0);
	vm->nc.wright = subwin(stdscr, LINES, 5 * COLS / 20, 0, 15 * COLS / 20);
	box(vm->nc.wleft, ACS_VLINE, ACS_HLINE);
	box(vm->nc.wright, ACS_VLINE, ACS_HLINE);
	init_left_panel(vm);
	status_game(vm);
	vm->nc.buffer = NULL;
	wrefresh(vm->nc.wleft);
}
