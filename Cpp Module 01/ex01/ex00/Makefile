NAME = Zombie
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJS= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Zombie.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: clean fclean all

.PHONY: clean