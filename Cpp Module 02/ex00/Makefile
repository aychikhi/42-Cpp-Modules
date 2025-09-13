NAME= Fixed
CC= c++
CFLAGS= -Wall -Wextra -Werror -std=c++98
SRCS= main.cpp Fixed.cpp

OBJS= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Fixed.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re: clean fclean all

.PHONY: clean