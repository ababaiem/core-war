# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababaie- <ababaie-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 18:04:58 by ababaie-          #+#    #+#              #
#    Updated: 2020/10/30 10:50:52 by ababaie-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

# Sources
SOURCES_DIR = ./
SOURCES_LIST = \
	cursor.c \
	init_structs.c \
	champs_to_vm.c \
	champ_reader.c \
	args.c \
	game.c \
	game_2.c \
	game_3.c \
	calculations.c \
	cycles_to_die.c \
	messages.c \
	error_handler.c \
	main.c \
	exec.c \
	output.c \
	str_utils.c \
	options.c \

OP_SOURCES_DIR = $(SOURCES_DIR)op/
OP_SOURCES_LIST = \
	live.c \
	add.c \
	aff.c \
	and.c \
	fork.c \
	ld.c \
	ldi.c \
	lfork.c \
	lld.c \
	lldi.c \
	or.c \
	st.c \
	sti.c \
	sub.c \
	xor.c \
	zjmp.c \

SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))
OP_SOURCES = $(addprefix $(OP_SOURCES_DIR), $(OP_SOURCES_LIST))

# Objects
OBJECTS_DIR = ./obj/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))
OP_OBJECTS_LIST = $(patsubst %.c, %.o, $(OP_SOURCES_LIST))
OP_OBJECTS = $(addprefix $(OBJECTS_DIR), $(OP_OBJECTS_LIST))

# Headers
HEADERS_DIR = ./includes/
HEADERS_LIST = \
	corewar.h \
	commands.h \
	errors.h \
	op.h


HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))
INCLUDES = \
	-I$(HEADERS_DIR) \
	-I$(LIB_DIR)libft/ \

# Lib
LIB_DIR = ../lib/
LIB = -lft -L$(LIB_DIR)

# Colors
GREEN = @tput setaf 2; tput bold;
RED = @tput setaf 1; tput bold;
MAGENTA = @tput setaf 5; tput bold;
CYAN = @tput setaf 6; tput bold;
RESET = @tput setaf 7;


CC = gcc

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	FLAGS =
endif
ifeq ($(UNAME), Darwin)
	FLAGS = -Wall -Wextra -Werror
endif

all: $(NAME)

$(NAME): $(OBJECTS_DIR) $(OBJECTS) $(OP_OBJECTS)
	@make -C $(LIB_DIR)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) $(OP_OBJECTS) -o $(NAME) $(LIB)
	$(GREEN)
	@echo "$(NAME) object files were created"
	@echo "$(NAME) was created"
	$(RESET)

$(LIB):
	@make -C $(LIB_DIR)

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	$(CYAN)
	@echo "+"
	$(RESET)

$(OBJECTS_DIR)%.o : $(OP_SOURCES_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	$(CYAN)
	@echo "+"
	$(RESET)

clean:
	@cd ../lib && make fclean && cd ../asmd
	@rm -rf $(OBJECTS_DIR)
	$(RED)
	@echo "$(NAME) objects were deleted"
	$(RESET)

fclean:	clean
	@rm -f $(NAME)
	$(RED)
	@echo "$(NAME) was deleted"
	$(RESET)
re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
