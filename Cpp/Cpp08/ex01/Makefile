NAME		=span
CC			=c++
CFLAGS		=-Wall -Wextra -Werror  -std=c++98
RM			=rm -f
SRC			=main.cpp Span.cpp
HEADERS		=Span.hpp
OBJ = $(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(SRC) $(OBJ) $(HEADERS)
				@$(CC) $(CFLAGS) $(OBJ) -o   $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
				@$(RM) $(NAME)

re: 		fclean all

.PHONY:		all fclean re