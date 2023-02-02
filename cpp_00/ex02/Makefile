NAME = ex02

SRC = tests.cpp Account.cpp

OBJ = $(addprefix obj/,$(SRC:.cpp=.o))

COMPILE = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(FLAGS) $^ -o $@

obj/%.o: %.cpp | obj
	$(COMPILE) $(FLAGS) -c $< -o $@

obj:
	mkdir obj

clean:
	rm -rf obj

fclean: clean
	rm -r $(NAME)

re: fclean all

.PHONY: all clean fclean re
