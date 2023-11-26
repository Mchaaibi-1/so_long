# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 22:40:29 by mchaaibi          #+#    #+#              #
#    Updated: 2023/11/25 20:36:39 by mchaaibi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc -g

CFLAGS = -Wall -Wextra -Werror

HEADER = so_long.h

SOURCES =  include.c map.c pars.c so_long.c \
			./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c\
			functions_mlx.c functions.c function.c fun_utilis.c exi_t.c \

OBJECTS = $(SOURCES:.c=.o)
MLX = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJECTS)  $(HEADER)
		 $(CC) $(CFLAGS) $(MLX)  $(SOURCES) -o $(NAME)

clean : 
		 rm -rf $(OBJECTS)

fclean : clean
		 rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re