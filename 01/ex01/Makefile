NAME =		moarBrainz

INCLUDES =	Zombie.hpp

SRC =		Zombie.cpp \
			zombieHorde.cpp \
			main.cpp

COMP = clang++

all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	$(COMP) -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME) -I.
