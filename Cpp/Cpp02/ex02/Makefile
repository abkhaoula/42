NAME		=a.out
CC			=c++
CFLAGS		=-Wall -Wextra -Werror -std=c++98 
RM			=rm -f
SRC			=Fixed.cpp main.cpp
HEADERS		=Fixed.hpp

all:		$(NAME)

$(NAME):	$(SRC) $(HEADERS)
				$(CC) $(CFLAGS) $(SRC) -o   $(NAME)

fclean: 	
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all fclean re