NAME		=push_swap
CC			=gcc
CFLAGS		=-Wall -Wextra -Werror
RM			=rm -f
SRC			= push_swap.c push_swap_utils.c ft_atoi.c ft_strlen.c \
		parse_stack.c to_binary.c push_swap_opps.c sort.c sort_utils.c \
		parse_utils.c
SRC_BONUS	= checker_bonus.c parse_stack.c parse_utils.c ft_atoi.c \
		ft_strlen.c push_swap_utils.c checker_ops1_bonus.c \
		checker_ops2_bonus.c

$(NAME):	$(SRC) $(SRC_BONUS)
				$(CC) -I. $(SRC) $(CFLAGS) -o $(NAME)
				$(CC) -I. $(SRC_BONUS) $(CFLAGS) -o checker

all:		$(NAME)

bonus:		$(NAME)

clean:
				$(RM) $(NAME)
				$(RM) checker

fclean: 	clean

re: 		fclean all

.PHONY:		all clean fclean re bonus