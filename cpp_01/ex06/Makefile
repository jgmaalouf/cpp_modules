VPATH = src

NAME = harlFilter

SRC = main.cpp Harl.cpp

OBJ = $(addprefix obj/,$(SRC:.cpp=.o))

COMPILE = c++

INCL = -I include

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(FLAGS) $(INCL) $^ -o $@

obj/%.o: %.cpp | obj
	$(COMPILE) $(FLAGS) $(INCL) -c $< -o $@

obj:
	mkdir obj

clean:
	rm -rf obj

fclean: clean
	rm -r $(NAME)

re: fclean all

.PHONY: all clean fclean re
