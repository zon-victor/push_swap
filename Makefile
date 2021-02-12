#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: zmakhube <marvin@42.fr>                    +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/06/28 11:11:10 by zmakhube          #+#    #+#             *#
#*   Updated: 2016/07/03 14:25:20 by zmakhube         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = push_swap
CH = checker
LIBFT = libft.a

ECHO = echo
RED_L = \033[1;31m
GREEN_L = \033[1;32m
GREEN = \033[0;32m
BLUE = \033[1;34m
RED = \033[0;31m
GRAY = \033[1;30m
GRAY_L = \033[0;37m
CYAN = \033[0;36m
PURPLE_L = \033[1;35m
CYAN_L = \033[1;36m
NC = \033[0m

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L./libft/ -lft
IFLAGS = -I./srcs/includes/ -I./libft/

SRCS_DIR = ./srcs/
INCS_DIR = ./srcs/includes/
OBJS_DIR = ./objs/

SRC_FILES = ps_main.c \
			ps_ai.c \
			ps_ai_extended.c \
			ps_ai_extended_again.c \
			ps_ai_exec.c \
	  		ps_swap.c \
			ps_swap_if.c \
			ps_push.c \
			ps_push_if.c \
			ps_rotate.c \
			ps_rotate_if.c \
			ps_reverse_rotate.c \
			ps_reverse_rotate_if.c

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRCS_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJS_DIR), $(OBJ_FILES))

all: $(OBJS_DIR) $(LIBFT) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	
norme: $(SRC)
	norminette $(SRC) $(INC)
$(LIBFT):
	@make -C libft/

$(NAME): $(OBJ)
	@$(ECHO) "\n$(BLUE)Linking $(CYAN) $(NAME) $(BLUE).\n"
	@$(CC) -o $@ $^ $(LFLAGS) $(IFLAGS)
	@$(ECHO) "$(CYAN) $(NAME) $(BLUE) binary created.\n"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
		@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<  
		@$(ECHO) "$(BLUE) - $(GRAY)Compiling ==> $(RED)$<$(GRAY) ... $(GREEN)OK! $(NC)"
clean:
	@$(ECHO) "$(BLUE) $(CYAN)Removed ==> $(RED) $(NAME) $(GRAY_L)object files$(GRAY).$(NC)"
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)
	@rm -rf libft/libft.a
	@$(ECHO) "$(BLUE) $(CYAN)Removed  ==> $(RED) $(LIBFT) $(GRAY_L)binary$(GRAY).\n"

re: fclean all

run: re
	@$(ECHO) "$(BLUE) Testing $(CYAN) $(NAME).\n"
	./$(NAME) 2 1 3 4 5
