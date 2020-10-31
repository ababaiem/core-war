/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchadwic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:09:33 by cchadwic          #+#    #+#             */
/*   Updated: 2020/10/31 00:57:45 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>

/*
** -------------------------- External Headers ---------------------------------
*/

# include "../libft/libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>

/*
** -------------------------- Macros Definition --------------------------------
*/

# define MAX(a, b)		(((b) & (((a) - (b)) >> 31)) | ((a) & (~((a) - (b)) >> 31)))
# define MIN(a, b)		(((a) & (((a) - (b)) >> 31)) | ((b) & (~((a) - (b)) >> 31)))
# define ABS(a)			(((a) < 0) ? -(a) : (a))
# define DABS(a)		(((a) < 0.0f) ? -(a) : (a))
# define STRERR			strerror

/*
** -------------------------- Colors Definition --------------------------------
*/

# define PF_RED			"\033[31m"
# define PF_GREEN		"\033[32m"
# define PF_YELLOW		"\033[33m"
# define PF_BLUE		"\033[34m"
# define PF_PURPLE		"\033[35m"
# define PF_CYAN		"\033[36m"
# define PF_EOC			"\033[0m"

/*
** --------------------------- Masks Definition --------------------------------
*/

/*
**(1 << 0) = 0x1
**(1 << 1) = 0x2
**(1 << 2) = 0x4
**(1 << 3) = 0x8
**(1 << 4) = 0x10
**(1 << 5) = 0x20
**(1 << 6) = 0x40
**(1 << 7) = 0x80
**(1 << 8) = 0x100
**(1 << 9) = 0x200
**(1 << 10) = 0x400
**(1 << 11) = 0x800
**(1 << 12) = 0x1000
**(1 << 13) = 0x2000
**(1 << 14) = 0x4000
**(1 << 15) = 0x8000
*/

# define F_SHARP		0x1
# define F_SPACE		0x2
# define F_PLUS			0x4
# define F_MINUS		0x8
# define F_ZERO			0x10
# define F_WILDCARD		0x20
# define F_UPCASE		0x40
# define F_SHORT		0x80
# define F_SHORT2		0x100
# define F_LONG			0x200
# define F_LONG2		0x400
# define F_INTMAX		0x800
# define F_SIZE_T		0x1000
# define F_MIN_LEN		0x2000
# define F_APP_PRECI	0x4000
# define F_POINTER		0x8000
# define PF_BUF_SIZE	64

/*
** ------------------------- Structure Definition ------------------------------
*/

typedef struct			s_printf
{
	int					len;
	short				f;
	short				n;
	int					min_length;
	int					precision;
	int					padding;
	int					printed;
	int					fd;
	int					buffer_index;
	char				buff[PF_BUF_SIZE];
	va_list				ap;
	char				*format;
	unsigned			c;
}						t_printf;

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/

int						ft_printf(const char *format, ...);
int						ft_dprintf(int fd, const char *format, ...);

/*
** -------------------------- Parsing Functions --------------------------------
*/

void					parse_optionals(t_printf *p);
void					cs_not_found(t_printf *p);

/*
** -------------------------- Numbers Functions --------------------------------
*/

void					pf_putnb(t_printf *p);
void					pf_putnb_base(int base, t_printf *p);
void					itoa_printf(intmax_t d, t_printf *p, int len);
void					itoa_base_printf(uintmax_t d, int b, t_printf *p);
void					itoa_base_fill(uintmax_t tmp, int base, char *str,
						t_printf *p);

/*
** ---------------------- Strings & Chars Functions ----------------------------
*/

void					pf_putstr(t_printf *p);
void					pf_putwstr(t_printf *p);
void					pf_character(t_printf *p, unsigned c);
void					ft_printf_putstr(char *s, t_printf *p);
void					pf_putwchar(t_printf *p, unsigned int w, int wl, int n);

/*
** --------------------------- Bonus Functions ---------------------------------
*/

void					print_pointer_address(t_printf *p);
void					color(t_printf *p);
void					pf_putdouble(t_printf *p);

/*
** --------------------------- Buffer Functions --------------------------------
*/

void					buffer(t_printf *p, void *new_elem, size_t size);
void					buffer_flush(t_printf *p);

void					padding(t_printf *p, int n);

#endif
