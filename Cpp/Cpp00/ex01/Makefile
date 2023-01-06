# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 12:06:11 by kabdenou          #+#    #+#              #
#    Updated: 2023/01/06 13:50:08 by kabdenou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=phonebook
CC			=c++
CFLAGS		=-Wall -Wextra -Werror -std=c++98
RM			=rm -f
SRC			= phoneBook.cpp main.cpp
HEADERS		= ./phoneBook.hpp


$(NAME):	$(SRC) $(HEADERS)
				$(CC) $(CFLAGS) $(SRC) -o   $(NAME)

all:		$(NAME)

fclean: 	
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all fclean re