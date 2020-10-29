/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaie- <ababaie-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:14:13 by ababaie-          #+#    #+#             */
/*   Updated: 2020/10/29 19:05:33 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_add(t_vm *vm, t_cursor *cursor)
{
	int reg1;
	int reg2;
	int reg3;
	int value;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	reg1 = get_byte(cursor->pos + cursor->step, vm);
	cursor->step += REG_LEN;
	reg2 = get_byte(cursor->pos + cursor->step, vm);
	cursor->step += REG_LEN;
	value = cursor->reg[reg1 - 1] + cursor->reg[reg2 - 1];
	if (value == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
	reg3 = get_byte(cursor->pos + cursor->step, vm);
	cursor->reg[reg3 - 1] = value;
	cursor->step += REG_LEN;
	(g_flags.verbal & V_MASK_4) ? ft_printf("P %4d | add r%d r%d r%d\n",
								cursor->id, reg1, reg2, reg3) : 0;
}
