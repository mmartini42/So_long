# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathmart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 17:24:21 by mathmart          #+#    #+#              #
#    Updated: 2021/12/02 19:10:00 by mathmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREY = \033[4;34m
RED = \033[1;31m
GREEN = \033[3;32m
YELLOW = \033[2;49;33m
BLUE = \033[4;34m
BLUEE = \033[3;34m
PURPLE = \033[3;35m
CYAN = \033[3;36m
RESET = \033[0m
ICONOK = \033[1;32m
ICONKO = \033[1;31m
CO_DELET = \033[4;31m
CO_A_OUT = \033[96m
WHITE = \033[1;49;97m

# Executable
NAME = Solong

# Include
HEADER = ./Includes/Solong.h

# Lib
LIB_PERSO = ./libft
LIB_MLX = ./Mlx

LIB = -L Mlx -l Mlx

# chemin Sources
. = Sources/

D = sources/bettermlx/display/

H = sources/bettermlx/hook/

W = sources/bettermlx/window/

C = Sources/Close/

I = Sources/Init/

M = sources/Move/

P = sources/Parsing/

SRCS = $(D)bettermlx_clean_display.c \
	$(D)bettermlx_draw_line.c \
	$(D)bettermlx_get_color.c \
	$(D)bettermlx_get_memory_position.c \
	$(D)bettermlx_pixel_put.c \
	$(D)bettermlx_put_image.c \
	$(D)bettermlx_render.c \
	$(D)bettermlx_set_color.c \
	$(H)bettermlx_hook.c \
	$(H)bettermlx_register_loop.c \
	$(W)bettermlx_destroy_image.c \
	$(W)bettermlx_destroy_window.c \
	$(W)bettermlx_init_image.c \
	$(W)bettermlx_init_window.c \
	$(W)bettermlx_init_xpm_image.c \
	$(C)So_esc.c \
	$(C)So_redcross.c \
	$(I)so_init.c \
	$(M)so_move.c \
	$(P)Start_Parsing.c \
	$(P)validate_map.c \
	sources/main.c
# sources/Put_groud.c \


# normal Flags
CC = gcc

LIBFT = ./libft/libft.a

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -glldb -flto -march=native -ffast-math -I ./Includes

all: $(NAME) $(HEADER)

%.o: %.c $(HEADER)
	@printf "\033[2K\r$(PURPLE)$<: $(CYAN)loading..$(RESET)"
	@gcc $(CFLAGS) -c $< -o $@

$(NAME): $(HEADER) $(OBJS)
	@make -C $(LIB_PERSO)
	@make -C $(LIB_MLX)
	@gcc $(CFLAGS) $(LIB) $(SRCS) -framework OpenGL -framework AppKit libft/libft.a -o $(NAME)
	@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUEE): $(ICONOK)Compiled [√]$(RESET)\n"

clean:
	@make clean -C $(LIB_PERSO)
	@make clean -C $(LIB_MLX)
	@$(RM) $(OBJS)
	@printf "\033[1;31mDelete OBJS $(CO_DELET)$(NAME)\033[3;32m [√]\033[0m\n"

fclean:
	@make fclean -C $(LIB_PERSO)
	@make clean -C $(LIB_MLX)
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@$(RM) -rf Solong.dSYM a.out
	@printf "\033[1;31mDelete $(CO_DELET)$(NAME)\033[3;32m [√]\033[0m\n"

re: fclean all

.PHONY: re fclean clean all
