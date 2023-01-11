NAME		=a.out
CC			=c++
CFLAGS		=-Wall -Wextra -Werror -std=c++98 
RM			=rm -f
SRC			=Animal.cpp Dog.cpp Cat.cpp main.cpp WrongAnimal.cpp WrongCat.cpp
HEADERS		=Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp
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