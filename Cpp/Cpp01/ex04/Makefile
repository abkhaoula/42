# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 17:24:01 by kabdenou          #+#    #+#              #
#    Updated: 2023/01/06 17:24:02 by kabdenou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=main
CC			=c++
CFLAGS		=-Wall -Wextra -Werror -std=c++98 
RM			=rm -f
SRC			=main.cpp

all:		$(NAME)


$(NAME):	$(SRC)
				$(CC) $(CFLAGS) $(SRC) -o   $(NAME)



fclean: 	
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all fclean re