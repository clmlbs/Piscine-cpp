# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 08:01:18 by cleblais          #+#    #+#              #
#    Updated: 2023/05/14 19:41:39 by cleblais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		form

SRCS		=		main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp \
					RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJS		= 		$(SRCS:.cpp=.o)

CC			=		c++

CFLAGS		=		-Wall -Wextra -Werror -g -std=c++98 

RM			= 		rm -f

all			:		$(NAME)

$(NAME)		:		$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
					$(RM) $(OBJS)

fclean		:		clean
					$(RM) $(NAME)

re			:		fclean all
