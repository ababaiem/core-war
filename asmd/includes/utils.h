/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaie- <ababaie-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:08:49 by ababaie-          #+#    #+#             */
/*   Updated: 2020/10/29 18:08:49 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H
# include "asm.h"

int		is_whitespace(char c);
int		is_delimiter(char c);
char	*strjoin_free(t_bool s1_b, t_bool s2_b, char *s1, char *s2);
int		is_register(const char *token);

#endif
