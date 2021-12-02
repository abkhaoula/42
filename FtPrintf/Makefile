NAME		=libftprintf.a
CC			=gcc
CFLAGS		=-Wall -Wextra -Werror
RM			=rm -f
SRC			= ft_printf.c ft_itoa.c ft_itoa_u.c ft_putstr.c ft_strdup.c \
				ft_strlen.c ft_putchar.c ft_printf_utils.c
OBJ			= $(SRC:.c=.o)

$(NAME):	$(OBJ)
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)

%.o:		%.c
				$(CC) -I. -o $@ -c $? $(CFLAGS)

all:		$(NAME)

bonus:		$(NAME)

clean:
				$(RM) $(OBJ) $(BONUS_OBJ)

fclean: 	clean
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re bonus