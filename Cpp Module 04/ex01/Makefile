NAME= Animals
CC= c++
CFLAGS= -Wall -Wextra -Werror -std=c++98
SRCS= main.cpp ./sources/Animal.cpp ./sources/Dog.cpp ./sources/Cat.cpp ./sources/WrongAnimal.cpp ./sources/WrongCat.cpp ./sources/Brain.cpp

OBJS= $(SRCS:.cpp=.o)

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp ./includes/Animal.hpp ./includes/Dog.hpp ./includes/Cat.hpp ./includes/WrongAnimal.hpp ./includes/WrongCat.hpp ./includes/Brain.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean