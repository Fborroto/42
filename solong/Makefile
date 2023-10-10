# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 18:50:23 by fborroto          #+#    #+#              #
#    Updated: 2023/07/21 01:03:20 by fborroto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		utils/ft_split.c utils/ft_str.c utils/ft_error.c game_utils/get_map.c \
		game_utils/ft_images.c game_utils/map_validator.c game_utils/get_element.c \
		game_utils/ft_keys.c game_utils/end_game.c game_utils/game_loop.c\

OBJS = ${SRCS:.c=.o}

CC = gcc
RM	= rm -f

CFLAGS = -Wall -Wextra -Werror
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
LINKS += -Lmlx_linux ./mlx_linux/libmlx.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
FLAGS_LINUX = -I/usr/include -Imlx_linux -O3
endif

ifeq ($(UNAME_S),Darwin)
LINKS += -lmlx -framework OpenGL -framework Appkit
endif

%.c%.o:
		$(CC)  -c $< -o $@
		
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LINKS) -o $(NAME)

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:	fclean all

leak: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./so_long map0.ber
leaks: all
	@Leaks --atExit -- ./$(NAME) map0.ber 

.PHONY: all fclean clean re