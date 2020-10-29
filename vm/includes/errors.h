/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaie- <ababaie-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:13:11 by ababaie-          #+#    #+#             */
/*   Updated: 2020/10/29 18:13:11 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/*
** Constants for error messages
*/
# define READ_ERROR "Error: Can't read source file "
# define INVALID_HEADER_ERROR "Error: Invalid magic header in champion file\n"
# define INVALID_FILE_ERROR "Error: File has mistake "
# define INTERNAL_ERROR "Error: Internal error occurred, can't init memory\n"
# define CHAMP_CODE_ERROR "Error: Invalid code size "
# define DOUBLE_INDEX_ERROR "Error: Two champions have same id\n"
# define MANY_CHAMPS_ERROR "Error: Too many champions\n"
# define CODE_SIZE_ERROR

#endif
