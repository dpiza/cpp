NAME =		ClapTrap

INCLUDES =	ClapTrap.hpp

SRC =		ClapTrap.cpp \
			main.cpp

COMP = clang++

all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	$(COMP) -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME) -I.
