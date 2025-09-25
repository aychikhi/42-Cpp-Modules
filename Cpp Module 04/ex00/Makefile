NAME = Animals
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp ./sources/Animal.cpp ./sources/Dog.cpp ./sources/Cat.cpp ./sources/WrongAnimal.cpp ./sources/WrongCat.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp ./includes/Animal.hpp ./includes/Dog.hpp ./includes/Cat.hpp ./includes/WrongAnimal.hpp ./includes/WrongCat.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re