VPATH = src

NAME = ex02

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

COMPILE = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(FLAGS) $^ -o $@

%.o: %.cpp
	$(COMPILE) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -r $(NAME)

re: fclean all

.PHONY: all clean fclean re
