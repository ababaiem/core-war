/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaie- <ababaie-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:11:18 by ababaie-          #+#    #+#             */
/*   Updated: 2020/10/29 18:11:18 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_usage(char *exec_name)
{
	ft_printf("Usage: %s [-d N -s N -v N |" \
"-n --stealth] [-a] <champion1.cor> <...>\n" \
"    -a        : Prints output from \"aff\" (Default is to hide it)\n" \
"#### TEXT OUTPUT MODE ####################################################\n" \
"    -d N      : Dumps memory after N cycles then exits\n" \
"    -s N      : Runs N cycles, dumps memory, pauses, then repeats\n" \
"    -v N      : Verbosity levels, can be added together to enable several\n" \
"                - 0 : Show only essentials\n" \
"                - 1 : Show lives\n" \
"                - 2 : Show cycles\n" \
"                - 4 : Show operations (Params are NOT litteral ...)\n" \
"#### SELECT PLAYERS NUMBER ###############################################\n" \
"    -n N cahmp.cor: Gives number N to the champion\n" \
"##########################################################################\n",
exec_name);
	exit(1);
}
