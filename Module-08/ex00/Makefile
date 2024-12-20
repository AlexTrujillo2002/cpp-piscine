NAME		= Easyfind
CPP_FLAGS	= -Wall -Werror -Wextra -std=c++98
SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)

all:	$(NAME)

%.o:	%.cpp
	c++ $(CPP_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	c++ $(CPP_FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: 	fclean all

e:		re
	./$(NAME)

.PHONY: all clean fclean re e