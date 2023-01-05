# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 13:08:18 by kabdenou          #+#    #+#              #
#    Updated: 2023/01/05 13:10:19 by kabdenou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=zombie
CC			=c++
CFLAGS		=-Wall -Wextra -Werror -std=c++98 -std=c++98
RM			=rm -f
SRC			=Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
HEADERS		=Zombie.hpp


$(NAME):	$(SRC) $(HEADERS)
				$(CC) $(CFLAGS) $(SRC) -o   $(NAME)

all:		$(NAME)

fclean: 	
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all fclean re