NAME= Bureaucrat
CXX= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
SRC= main.cpp Bureaucrat.cpp Form.cpp

OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Bureaucrat.hpp Form.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean fclean all

.PHONY: clean