# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 13:04:31 by lenakach          #+#    #+#              #
#    Updated: 2025/07/21 19:27:32 by lenakach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Nom de l'exec
NAME = so_long
NAME_BONUS = so_long_bonus

#Compilateur et flags
CC = cc
FLAGS = -Wall -Wextra -Werror
#Push_swap mandatory

#Dossiers
SRC_DIR = src
SRC_BONUS_DIR = bonus
LIBFT_DIR = libft
MINILIBX_DIR = minilibx-linux
GNL_DIR = libft/get_next_line

#Includes
INCLUDES = -Iincludes -I$(LIBFT_DIR)/includes -I$(MINILIBX_DIR)

#Bibliotheques
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MINILIBX_DIR)/libmlx.a
MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx -L/usr/libX11 -lXext -lX11 -lm -lz

#Sources
SRC = $(SRC_DIR)/map_parsing.c $(SRC_DIR)/map_utils.c $(SRC_DIR)/check_elements.c \
		$(SRC_DIR)/check_playability.c $(SRC_DIR)/free.c $(SRC_DIR)/map_utils2.c $(SRC_DIR)/key_press.c \
		$(SRC_DIR)/render_map.c $(SRC_DIR)/so_long.c $(SRC_DIR)/init.c
		
SRC_BONUS = $(SRC_BONUS_DIR)/map_parsing_bonus.c $(SRC_BONUS_DIR)/map_utils_bonus.c $(SRC_BONUS_DIR)/check_elements_bonus.c \
		$(SRC_BONUS_DIR)/check_playability_bonus.c $(SRC_BONUS_DIR)/free_bonus.c $(SRC_BONUS_DIR)/map_utils2_bonus.c $(SRC_BONUS_DIR)/key_press_bonus.c \
		$(SRC_BONUS_DIR)/render_map_bonus.c $(SRC_BONUS_DIR)/so_long_bonus.c \
		$(SRC_BONUS_DIR)/animation.c $(SRC_BONUS_DIR)/init.c

GNL = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c 

SRCS = $(GNL) $(SRC)
SRCS_BONUS = $(GNL) $(SRC_BONUS)
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
 
#Commandes
RM = rm -f

#Regles
all : $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@echo "Compilation de LIbft..."
	@make -C $(LIBFT_DIR)

$(MLX):
	@echo "Compilation de MiniLibX"
	@make -C $(MINILIBX_DIR)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

bonus: $(LIBFT) $(MLX) $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT) $(MLX) $(MLX_FLAGS)
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re test