/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababaie- <ababaie-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:11:18 by ababaie-          #+#    #+#             */
/*   Updated: 2020/10/29 19:04:13 by ababaie-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "fcntl.h"

int32_t		bytecode_to_int(const uint8_t *buf)
{
	uint32_t	res;
	uint8_t		sign;
	int			i;

	res = 0;
	sign = (buf[0] & 128);
	i = -1;
	while (++i < 4)
		if (sign)
			res += ((buf[i] ^ 0xFF) << ((BYTES - i - 1) * 8));
		else
			res += buf[i] << ((BYTES - i - 1) * 8);
	if (sign)
		res = ~res;
	return (res);
}

int32_t		read_int32(int fd, char *filename)
{
	int32_t			size;
	unsigned char	buf[4];

	if ((size = read(fd, buf, 4)) < 0)
		error_exit(READ_ERROR, filename);
	else if (size != 4)
		error_exit(INVALID_HEADER_ERROR, filename);
	return (bytecode_to_int(buf));
}

uint8_t		*read_bytecode(int fd, uint32_t read_size, char *filename)
{
	uint8_t	*buf;
	char	oversize_flag[1];
	int		len;

	if (!(buf = ft_memalloc(read_size)))
		error_exit(INTERNAL_ERROR, "");
	if ((len = read(fd, buf, read_size)) < 0 ||
	(read(fd, oversize_flag, 1)) != 0)
		error_exit(READ_ERROR, filename);
	if ((uint32_t)len != read_size)
		error_exit(INVALID_FILE_ERROR, filename);
	return (buf);
}

char		*read_string(int fd, uint32_t read_size, char *filename)
{
	char	*buf;
	int		len;

	if (!(buf = ft_memalloc(read_size)))
		error_exit(INTERNAL_ERROR, "");
	if ((len = read(fd, buf, read_size)) < 0)
		error_exit(READ_ERROR, filename);
	if ((uint32_t)len != read_size)
		error_exit(INVALID_FILE_ERROR, filename);
	return (buf);
}

t_player	*read_champion_file(char *filename, int id)
{
	t_player	*player;
	int			fd;

	player = init_player(id);
	if ((fd = open(filename, O_RDONLY)) < 0)
		error_exit(READ_ERROR, filename);
	if (read_int32(fd, filename) != COREWAR_EXEC_MAGIC)
		error_exit(INVALID_HEADER_ERROR, filename);
	player->name = read_string(fd, PROG_NAME_LENGTH, filename);
	if (read_int32(fd, filename) != 0)
		error_exit(INVALID_FILE_ERROR, filename);
	player->code_size = read_int32(fd, filename);
	if ((player->code_size < 0) || (player->code_size > CHAMP_MAX_SIZE))
		error_exit(CHAMP_CODE_ERROR, filename);
	player->comment = read_string(fd, COMMENT_LENGTH, filename);
	if (read_int32(fd, filename) != 0)
		error_exit(INVALID_FILE_ERROR, filename);
	player->code = read_bytecode(fd, player->code_size, filename);
	return (player);
}
