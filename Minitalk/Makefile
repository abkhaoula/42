NAME_C		=client
NAME_S		=server
CC			=gcc
CFLAGS		=-Wall -Wextra -Werror
RM			=rm -f
SRC_C		= client.c ft_atoi.c
SRC_S		= server.c

all:		$(NAME_S) $(NAME_C)

$(NAME_S):	$(SRC_S)
				$(CC) $(SRC_S) $(CFLAGS) -o $(NAME_S)

$(NAME_C):	$(SRC_C)
				$(CC) $(SRC_C) $(CFLAGS) -o $(NAME_C)

clean:
				$(RM) $(NAME_C)
				$(RM) $(NAME_S)

fclean: 	clean

re: 		fclean all

.PHONY:		all clean fclean re bonus