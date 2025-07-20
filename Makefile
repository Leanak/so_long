# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 13:04:31 by lenakach          #+#    #+#              #
#    Updated: 2025/07/20 23:16:48 by lenakach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Nom de l'exec
NAME = so_long

#Compilateur et flags
CC = cc
FLAGS = -Wall -Wextra -Werror
#Push_swap mandatory

#Fichiers sources
LIBFT_DIR = libft
MINILIBX_DIR = minilibx-linux
INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

LIBFT = $(LIBFT_DIR)/libft.a

MOUV_DIR = mouvement
MOUV = $(MOUV_DIR)/key_press.c

MAP_DIR = maps
MAP = $(MAP_DIR)/map_parsing.c $(MAP_DIR)/map_utils.c $(MAP_DIR)/check_elements.c \
		$(MAP_DIR)/check_playability.c $(MAP_DIR)/free.c $(MAP_DIR)/map_utils2.c

AFF_DIR = affichage
AFF = $(AFF_DIR)/render_map.c

SRCS = $(GNL) $(MAP) $(AFF) $(MOUV) so_long.c
OBJS = $(SRCS:.c=.o)

#Commandes
RM = rm -f

#Regles
all : $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm -lz
	
%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) 
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re test