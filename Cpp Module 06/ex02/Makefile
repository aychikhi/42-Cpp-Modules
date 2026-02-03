NAME= convert
CXX= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
SRC= main.cpp Base.cpp

OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
 
%.o: %.cpp Base.hpp A.hpp B.hpp C.hpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean fclean all

.PHONY: clean