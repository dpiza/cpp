NAME =		violence

INCLUDES =	Weapon.hpp \
			HumanA.hpp \
			HumanB.hpp

SRC =		Weapon.cpp \
			HumanA.cpp \
			HumanB.cpp \
			main.cpp

COMP = clang++

all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	$(COMP) -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME) -I.
