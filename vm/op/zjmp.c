/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaie- <ababaie-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:14:13 by ababaie-          #+#    #+#             */
/*   Updated: 2020/10/29 18:14:13 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_zjmp(t_vm *vm, t_cursor *cursor)
{
	int val;

	cursor->step += OP_CODE_LEN;
	val = get_arg(vm, cursor, 1, 1);
	if (cursor->carry == 1)
	{
		cursor->pos = find_addr(cursor->pos + (val % IDX_MOD));
		cursor->step = 0;
	}
	if (g_flags.verbal & V_MASK_4)
	{
		ft_printf("P %4d | zjmp %d %s\n",
					cursor->id,
					val,
					(cursor->carry) ? "OK" : "FAILED");
	}
}
