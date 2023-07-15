# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 17:12:06 by cleblais          #+#    #+#              #
#    Updated: 2023/05/17 17:12:06 by cleblais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		convert

SRCS		=		$(wildcard *.cpp)

OBJS		= 		$(SRCS:.cpp=.o)

CC			=		c++

CXXFLAGS		=	-Wall -Wextra -Werror -g -std=c++98 

RM			= 		rm -f

all			:		$(NAME)

$(NAME)		:		$(OBJS)
					$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean		:
					$(RM) $(OBJS)

fclean		:		clean
					$(RM) $(NAME)

re			:		fclean all
