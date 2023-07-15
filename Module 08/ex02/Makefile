# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 12:29:39 by cleblais          #+#    #+#              #
#    Updated: 2023/05/22 17:13:38 by cleblais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		abomination

SRCS		=		$(wildcard *.cpp) 

OBJS		= 		$(SRCS:.cpp=.o)

CC			=		c++

CXXFLAGS	=		-Wall -Wextra -Werror -g -std=c++98 

RM			= 		rm -f

all			:		$(NAME)

$(NAME)		:		$(OBJS)
					$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean		:
					$(RM) $(OBJS)

fclean		:		clean
					$(RM) $(NAME)

re			:		fclean all
