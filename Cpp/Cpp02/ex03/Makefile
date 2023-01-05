NAME		=a.out
CC			=c++
CFLAGS		=-Wall -Wextra -Werror -std=c++98 
RM			=rm -f
SRC			=Point.cpp Fixed.cpp main.cpp


$(NAME):	$(SRC)
				$(CC) -o $@ $? $(CFLAGS)

all:		$(NAME)

fclean: 	
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all fclean re