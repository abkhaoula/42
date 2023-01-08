NAME		=a.out
CC			=c++
CFLAGS		=-Wall -Wextra -Werror -std=c++98 
RM			=rm -f
SRC			=Point.cpp Fixed.cpp main.cpp bsp.cpp
HEADERS		=Fixed.hpp Fixed.h

all:		$(NAME)

$(NAME):	$(SRC) $(HEADERS)
				$(CC) $(CFLAGS) $(SRC) -o   $(NAME)

fclean: 	
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all fclean re