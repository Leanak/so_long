# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 11:52:01 by lenakach          #+#    #+#              #
#    Updated: 2025/07/21 14:11:19 by lenakach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de la librairie
NAME = libft.a

#Compilateur et flags
CC = cc
FLAGS = -Wall -Wextra -Werror -I$(INC)
INCLUDES = includes
#Fichiers sources et objets
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/ft_print_char.c $(PRINTF_DIR)/ft_print_int.c \
		$(PRINTF_DIR)/ft_print_string.c $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_print_p.c $(PRINTF_DIR)/ft_print_unsigned.c \
		$(PRINTF_DIR)/ft_print_hexa.c $(PRINTF_DIR)/ft_print_hexamaj.c

GNL_DIR = get_next_line
SRCS = $(PRINTF) ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
		
SRCS_BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c \
			ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

#Commandes
RM = rm -f
AR = ar rcs

#Creation des .o a partir des .c 
%.o: %.c
	$(CC) $(FLAGS) -I$(INCLUDES) -c $< -o $@

#Regle principale
all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS_BONUS)

# Nettoyage des .o
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

# Suppression de tous les fichiers générés
fclean: clean
	$(RM) $(NAME)

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re test