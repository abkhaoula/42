NAME		=harl
CC			=c++
CFLAGS		=-Wall -Wextra -Werror -std=c++98 
RM			=rm -f
SRC			= Harl.cpp main.cpp
HEADERS		= Harl.cpp

all:		$(NAME)

$(NAME):	$(SRC) $(HEADERS)
				$(CC) $(CFLAGS) $(SRC) -o   $(NAME)

all:		$(NAME)

fclean: 	
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all fclean re