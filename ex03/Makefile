# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/24 16:05:25 by dhuss             #+#    #+#              #
#    Updated: 2025/03/25 16:02:34 by dhuss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CPPFILES = main.cpp\
	Bureaucrat.cpp\
	AForm.cpp\
	ShrubberyCreationForm.cpp\
	PresidentialPardonForm.cpp\
	RobotomyRequestForm.cpp\
	Intern.cpp
FLAGS = -Wall -Werror -Wextra -std=c++17
OFILES = $(CPPFILES:.cpp=.o)
NAME = ex03

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OFILES)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re