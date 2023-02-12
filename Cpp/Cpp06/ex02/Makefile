NAME		= identify
CC			=c++
CFLAGS		=-Wall -Wextra -Werror
RM			=rm -f
SRC			= main.cpp B.cpp C.cpp A.cpp Base.cpp
HEADERS		= B.hpp C.hpp A.hpp Base.hpp
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