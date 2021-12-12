NAME		=push_swap
CC			=gcc
CFLAGS		=-Wall -Wextra -Werror
RM			=rm -f
SRC			= push_swap.c ft_atoi.c ft_strlen.c

$(NAME):	$(SRC)
				$(CC) -I. $? $(CFLAGS) -o $@

all:		$(NAME)

bonus:		$(NAME)

clean:
				$(RM) $(NAME)

fclean: 	clean

re: 		fclean all

.PHONY:		all clean fclean re bonus