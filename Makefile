# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 13:04:31 by lenakach          #+#    #+#              #
#    Updated: 2025/07/20 21:38:03 by lenakach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Nom de l'exec
NAME = so_long

#Compilateur et flags
CC = cc
FLAGS = -Wall -Wextra -Werror
#Push_swap mandatory

#Fichiers sources
GNL_DIR = get_next_line
GNL = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

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
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz
	
%.o: %.c
	$(CC) $(FLAGS) -I./includes -Iminilibx-linux -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re test