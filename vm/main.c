/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaie- <ababaie-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:11:18 by ababaie-          #+#    #+#             */
/*   Updated: 2020/10/29 19:04:55 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_abs(const int x)
{
	return (x > 0 ? x : -x);
}

static void	print_last_alive(t_vm *vm)
{
	ft_printf("Contestant %d, \"%s\", has won !\n",
				ft_abs(vm->last_alive->id),
				vm->last_alive->name);
}

static void	init_flags(void)
{
	g_flags.dump = -1;
	g_flags.verbal = 0;
	g_flags.aff = 0;
	g_flags.player_num = 0;
}

int			main(int ac, char **av)
{
	if (ac <= 1)
		print_usage(av[0]);
	g_vm = init_vm();
	init_flags();
	parse_args(ac, av);
	init_arena(g_vm);
	set_cursors(g_vm);
	print_intro(g_vm);
	fight(g_vm);
	print_last_alive(g_vm);
	return (0);
}
