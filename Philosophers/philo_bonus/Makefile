
SRCS	= main.c utils.c start.c

OBJS	= $(SRCS:.c=.o)

NAME	= philo_bonus

GCC	= gcc -pthread

FLAGS	= -Wall -Wextra -Werror

INCLUDE	= -lpthread

HEADER	= philo.h




all:	$(NAME)

$(NAME): $(OBJS)
	$(GCC) $(INCLUDE) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(GCC) $(FLAGS) -c $<  -o $(<:.c=.o)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY:	clean fclean re bonus bench bclean
