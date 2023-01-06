# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 12:05:47 by kabdenou          #+#    #+#              #
#    Updated: 2023/01/06 13:50:29 by kabdenou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=megaphone
CC			=c++
CFLAGS		=-Wall -Wextra -Werror -std=c++98
RM			=rm -f
SRC			= megaphone.cpp


$(NAME):	$(SRC)
				$(CC) $(CFLAGS) $? -o   $@

all:		$(NAME)

fclean: 	
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all fclean re