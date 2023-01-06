# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 13:18:40 by kabdenou          #+#    #+#              #
#    Updated: 2023/01/06 15:03:55 by kabdenou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=zombie
CC			=c++
CFLAGS		=-Wall -Wextra -Werror -std=c++98 -std=c++98
RM			=rm -f
SRC			=Zombie.cpp newZombie.cpp randomChump.cpp zombieHorde.cpp main.cpp
HEADERS		=Zombie.hpp Zombie.h

all:		$(NAME)

$(NAME):	$(SRC) $(HEADERS)
				$(CC) $(CFLAGS) $(SRC) -o   $(NAME)



fclean: 	
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all fclean re