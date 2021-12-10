# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathmart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 17:24:21 by mathmart          #+#    #+#              #
#    Updated: 2021/12/10 18:39:38 by mathmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ./Config/Sources.mk
-include ./Config/Header.mk

#################################################################################
#									Colors										#
#################################################################################

GREY		= \033[4;34m
RED			= \033[1;31m
GREEN		= \033[3;32m
YELLOW		= \033[2;49;33m
BLUE		= \033[4;34m
BLUEE		= \033[3;34m
PURPLE		= \033[3;35m
CYAN		= \033[3;36m
RESET		= \033[0m
ICONOK		= \033[1;32m
ICONKO		= \033[1;31m
CO_DELET	= \033[4;31m
CO_A_OUT	= \033[96m
WHITE		= \033[1;49;97m


#################################################################################
#									Variables									#
#################################################################################

NAME		= so_long
LIB_PERSO	= ./libft
LIB_MLX		= ./Mlx
LIB			= -L Mlx -l Mlx
LIBFT		= ./Libft/libft.a
OBJS		= $(SRCS:%.c=%.o)
CFLAGS		= -Wall -Wextra -glldb -flto -march=native -ffast-math -I ./Includes
OBJ_DIR 	= Objects
OBJ_PATH	= $(addprefix $(OBJ_DIR)/, $(OBJS))


#################################################################################
#									Compilation Objects							#
#################################################################################

$(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	@mkdir -p $(@D)
	@gcc $(CFLAGS) -c $< -o $@
	@printf "\033[2K\r$(PURPLE)$<: $(CYAN)loading..$(RESET)"

#################################################################################
#									Compilation C								#
#################################################################################

$(NAME): $(LIBFT) $(OBJ_PATH) $(HEADER)
	@$(MAKE) -C $(LIB_MLX)
	@gcc $(CFLAGS) $(LIB) $(SRCS) -framework OpenGL -framework AppKit $(LIBFT) -o $(NAME)
	@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUEE): $(ICONOK)Compiled [√]$(RESET)\n"

all: gmk $(LIBFT) $(NAME) $(HEADER)

#################################################################################
#									Prerequis									#
#################################################################################

$(OBJ_DIR):
	@printf "\033[1;32mCreate OBJS_DIR $(CO_DELET)\033[3;32m [√]\033[0m\n"

$(LIBFT):
	@$(MAKE) -C Libft/

#################################################################################
#									Clean										#
#################################################################################

clean:
	@$(MAKE) clean -C $(LIB_PERSO)
	@$(MAKE) clean -C $(LIB_MLX)
	@$(RM) $(OBJ_PATH)
	@printf "\033[1;31mDelete OBJS $(CO_DELET)$(NAME)\033[3;32m [√]\033[0m\n"

fclean:
	@$(MAKE) fclean -C $(LIB_PERSO)
	@$(MAKE) clean -C $(LIB_MLX)
	@$(RM) $(OBJ_PATH)
	@$(RM) $(NAME)
	@$(RM) -rf Solong.dSYM a.out
	@printf "\033[1;31mDelete $(CO_DELET)$(NAME)\033[3;32m [√]\033[0m\n"

#################################################################################
#									Gen MK										#
#################################################################################

gmk:
	@echo "SRCS += " > ./Config/Sources.mk
	@find Sources -name '*.c' | sed 's/^/SRCS += /' >> ./Config/Sources.mk
	@echo "HEADER += " > ./Config/Header.mk
	@find Includes -name '*.h' | sed 's/^/HEADER += /' >> ./Config/Header.mk
	@find Libft -name '*.h' | sed 's/^/HEADER += /' >> ./Config/Header.mk
	@find Mlx -name '*.h' | sed 's/^/HEADER += /' >> ./Config/Header.mk

#################################################################################
#									Clena & Compilation							#
#################################################################################

re: fclean all

.PHONY: re fclean clean all
