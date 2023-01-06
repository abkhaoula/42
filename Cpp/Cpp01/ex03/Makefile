# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 17:23:50 by kabdenou          #+#    #+#              #
#    Updated: 2023/01/06 17:23:51 by kabdenou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=main
CC			=c++
CFLAGS		=-Wall -Wextra -Werror -std=c++98 -std=c++98
RM			=rm -f
SRC			=HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
HEADERS		=HumanA.hpp HumanB.hpp Weapon.hpp

all:		$(NAME)

$(NAME):	$(SRC) $(HEADERS)
				$(CC) $(CFLAGS) $(SRC) -o   $(NAME)




fclean: 	
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all fclean re