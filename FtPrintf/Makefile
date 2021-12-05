NAME		=libftprintf.a
CC			=gcc
CFLAGS		=-Wall -Wextra -Werror
RM			=rm -f
SRC			= ft_printf.c ft_itoa.c ft_itoa_u.c ft_putstr.c ft_strdup.c \
				ft_strlen.c ft_putchar.c ft_printf_utils.c ft_printf_bonus.c \
				plus_flag_bonus.c minus_flag_bonus.c ft_atoi.c \
				zero_flag_bonus.c sharp_flag_bonus.c space_flag_bonus.c \
				dot_flag_bonus.c
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