/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 00:19:09 by alborz            #+#    #+#             */
/*   Updated: 2020/10/31 01:23:23 by alborz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(const int a, const int b)
{
	return ((b & ((a - b) >> 31)) | (a & (~(a - b) >> 31)));
}
