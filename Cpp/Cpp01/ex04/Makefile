NAME		=main
CC			=c++
CFLAGS		=-Wall -Wextra -Werror -std=c++98 
RM			=rm -f
SRC			=main.cpp

all:		$(NAME)


$(NAME):	$(SRC)
				$(CC) $(CFLAGS) $(SRC) -o   $(NAME)



fclean: 	
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all fclean re