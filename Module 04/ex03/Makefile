# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 08:01:18 by cleblais          #+#    #+#              #
#    Updated: 2023/05/12 18:51:05 by cleblais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		materia

SRCS		=		main.cpp AMateria.cpp Character.cpp	Cure.cpp Ice.cpp \
					MateriaSource.cpp

OBJS		= 		$(SRCS:.cpp=.o)

CC			=		c++

CFLAGS		=		-Wall -Wextra -Werror -g -std=c++98 #-fsanitize=address

RM			= 		rm -f

all			:		$(NAME)

$(NAME)		:		$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
					$(RM) $(OBJS)

fclean		:		clean
					$(RM) $(NAME)

re			:		fclean all
