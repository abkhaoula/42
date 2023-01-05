NAME		=main
CC			=c++
CFLAGS		=-Wall -Wextra -Werror -std=c++98 -std=c++98
RM			=rm -f
SRC			=main.cpp


$(NAME):	$(SRC)
				$(CC) -o $@ $? $(CFLAGS)

all:		$(NAME)

fclean: 	
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all fclean re