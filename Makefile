


NAME = so_long


HEADER = so_long.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = so_long.c include.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	 map.c libft.c pars.c function_mlx.c 

OBJ = $(FILES:.c=.o)


all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ)  $(FILES) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re