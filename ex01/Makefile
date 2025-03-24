CC = c++
CPPFILES = main.cpp\
	Bureaucrat.cpp
FLAGS = -Wall -Werror -Wextra -std=c++17
OFILES = $(CPPFILES:.cpp=.o)
NAME = ex00

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OFILES)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re