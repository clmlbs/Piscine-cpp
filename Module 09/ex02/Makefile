NAME		=		PmergeMe

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
