NAME		=account
CC			=c++
CFLAGS		=-Wall -Wextra -Werror -std=c++98 -std=c++98
RM			=rm -f
SRC			= Account.cpp tests.cpp


$(NAME):	$(SRC)
				$(CC) -o $@ $? $(CFLAGS)

all:		$(NAME)

fclean: 	
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all fclean re