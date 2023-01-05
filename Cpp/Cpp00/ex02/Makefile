# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 12:06:48 by kabdenou          #+#    #+#              #
#    Updated: 2023/01/05 12:06:49 by kabdenou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=account
CC			=c++
CFLAGS		=-Wall -Wextra -Werror -std=c++98
RM			=rm -f
SRC			= Account.cpp tests.cpp
HEADERS		= ./Account.hpp


$(NAME):	$(SRC) $(HEADERS)
				$(CC) $(CFLAGS) $(SRC) -o   $(NAME)

all:		$(NAME)

fclean: 	
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all fclean re