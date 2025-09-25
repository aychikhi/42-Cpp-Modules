NAME= Materia
CC= c++
CFLAGS= -Wall -Wextra -Werror -std=c++98
SRCS= main.cpp ./sources/AMateria.cpp ./sources/Character.cpp ./sources/Cure.cpp ./sources/Ice.cpp ./sources/MateriaSource.cpp\

OBJS= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp ./includes/AMateria.hpp ./includes/Cure.hpp ./includes/Ice.hpp ./includes/Character.hpp ./includes/ICharacter.hpp ./includes/IMateriaSource.hpp ./includes/MateriaSource.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: clean fclean all

.PHONY: clean
