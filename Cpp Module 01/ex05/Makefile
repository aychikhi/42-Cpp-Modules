NAME = Harl
CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp harl.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c Harl.hpp
	$(CC) $(FLAGS) -c $> -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: clean fclean all

.PHONY: clean