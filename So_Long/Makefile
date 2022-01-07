NAME		=so_long
CC			=gcc
CFLAGS		=-Wall -Wextra -Werror
RM			=rm -f
SRC			= so_long.c

$(NAME):	$(SRC)
				$(CC) $(SRC) $(CFLAGS) -Lmlx -lmlx -lXext -lX11 -I minilibx-linux -L minilibx-linux -o $(NAME)

all:		$(NAME)

bonus:		$(NAME)

clean:
				$(RM) $(NAME)

fclean: 	clean

re: 		fclean all

.PHONY:		all clean fclean re bonus