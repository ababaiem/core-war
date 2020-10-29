# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababaie- <ababaie-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 18:02:36 by ababaie-          #+#    #+#              #
#    Updated: 2020/10/29 18:02:39 by ababaie-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = full

# lib
LIB_DIR	= lib/
LIBFT	= $(LIB_DIR)libft.a
LIB		= -lft -L$(LIB_DIR)

# core_war
COREWAR_DIR	= vm/
COREWAR		= $(COREWAR_DIR)corewar

# asm
ASM_DIR = asmd/
ASM 	= $(ASM_DIR)asm


all: $(NAME)

$(NAME):  
	@make -C $(LIB_DIR)
	@make -C $(ASM_DIR)
	@make -C $(COREWAR_DIR)
	@cp $(ASM) ./asm
	@cp $(ASM) ./Test_core/asm
	@cp $(COREWAR) ./corewar
	@cp $(COREWAR) ./Test_core/vm

clean:
	@make -C $(LIB_DIR) clean
	@make -C $(ASM_DIR) clean
	@rm -f asm
	@make -C $(COREWAR_DIR) clean
	@rm -f corewar

fclean: clean
	@make -C $(LIB_DIR) fclean
	@make -C $(ASM_DIR) fclean
	@make -C $(COREWAR_DIR) fclean

re:
	@make fclean
	@make all
