/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaie- <ababaie-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:13:11 by ababaie-          #+#    #+#             */
/*   Updated: 2020/10/29 18:13:11 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "corewar.h"

void			op_ld(t_vm *vm, t_cursor *cursor);
void			op_st(t_vm *vm, t_cursor *cursor);
void			op_add(t_vm *vm, t_cursor *cursor);
void			op_sub(t_vm *vm, t_cursor *cursor);
void			op_and(t_vm *vm, t_cursor *cursor);
void			op_or(t_vm *vm, t_cursor *cursor);
void			op_xor(t_vm *vm, t_cursor *cursor);
void			op_zjmp(t_vm *vm, t_cursor *cursor);
void			op_ldi(t_vm *vm, t_cursor *cursor);
void			op_sti(t_vm *vm, t_cursor *cursor);
void			op_fork(t_vm *vm, t_cursor *cursor);
void			op_lld(t_vm *vm, t_cursor *cursor);
void			op_lldi(t_vm *vm, t_cursor *cursor);
void			op_lfork(t_vm *vm, t_cursor *cursor);
void			op_aff(t_vm *vm, t_cursor *cursor);

#endif
