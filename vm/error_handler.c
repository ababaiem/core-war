/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaie- <ababaie-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:11:18 by ababaie-          #+#    #+#             */
/*   Updated: 2020/10/29 18:11:18 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <errno.h>

void	error_exit(char *message, char *filename)
{
	if (errno == 0)
	{
		ft_putstr_fd(message, 2);
		ft_putendl_fd(filename, 2);
	}
	else
	{
		ft_putstr_fd(message, 2);
		ft_putendl_fd(filename, 2);
	}
	exit(1);
}
