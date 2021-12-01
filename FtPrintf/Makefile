NAME		=libft.a
CC			=gcc
CFLAGS		=-Wall -Wextra -Werror
RM			=rm -f
SRC			= ft_printf.c
OBJ			= $(SRC:.c=.o)

$(NAME):	$(OBJ)
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)

%.o:		%.c
				$(CC) -I. -o $@ -c $? $(CFLAGS)

all:		$(NAME)

clean:
				$(RM) $(OBJ) $(BONUS_OBJ)

fclean: 	clean
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re bonus