NAME		=a.out
CC			=c++
CFLAGS		=-Wall -Wextra -Werror -std=c++98 
RM			=rm -f
SRC			=main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp 
HEADERS		=ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp 

all:		$(NAME)

$(NAME):	$(SRC) $(HEADERS)
				$(CC) $(CFLAGS) $(SRC) -o   $(NAME)

fclean: 	
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all fclean re