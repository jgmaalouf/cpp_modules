NAME = btc

SRC = main.cpp BitcoinExchange.cpp BitcoinExchangeUtils.cpp

OBJ = $(SRC:.cpp=.o)

COMPILE = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(FLAGS) $^ -o $@

%.o: %.cpp | obj
	$(COMPILE) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -r $(NAME)

re: fclean all

.PHONY: all clean fclean re
