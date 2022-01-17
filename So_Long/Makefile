NAME		=so_long
CC			=gcc
CFLAGS		=-Wall -Wextra -Werror
RM			=rm -f
SRC			= so_long.c map_dim.c map_dim_utils.c parse_map.c parse_map_utils.c render_map.c \
		map_to_tab.c handle_input_button.c ft_itoa.c handle_input_button_utils.c danger_position.c \
		coin_position.c animate.c ft_strjoin.c

$(NAME):	$(SRC)
				$(CC) $(SRC) $(CFLAGS) -Lmlx -lmlx -lXext -lX11 -I minilibx-linux -L minilibx-linux -o $(NAME)

all:		$(NAME)

bonus:		$(NAME)

clean:
				$(RM) $(NAME)

fclean: 	clean

re: 		fclean all

.PHONY:		all clean fclean re bonus