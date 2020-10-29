/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaie- <ababaie-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:14:13 by ababaie-          #+#    #+#             */
/*   Updated: 2020/10/29 18:14:13 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_fork(t_vm *vm, t_cursor *cursor)
{
	int			val;
	t_cursor	*new_cur;

	cursor->step += OP_CODE_LEN;
	val = get_arg(vm, cursor, 1, 1);
	new_cur = dupl_cur(cursor, val % IDX_MOD);
	add_cur(&(vm->cursors), new_cur);
	vm->cursors_num++;
	(g_flags.verbal & V_MASK_4) ? ft_printf("P %4d | fork %d (%d)\n",
									cursor->id, val,
									cursor->pos + val % IDX_MOD) : 0;
}
