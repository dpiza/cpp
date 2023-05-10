NAME =		ScavTrap

INCLUDES =	ClapTrap.hpp \
			ScavTrap.hpp

SRC =		ClapTrap.cpp \
			ScavTrap.cpp \
			main.cpp

COMP = clang++

all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	$(COMP) -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME) -I.
