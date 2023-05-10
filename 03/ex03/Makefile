NAME =		DiamondTrap

INCLUDES =	ClapTrap.hpp \
			ScavTrap.hpp \
			FragTrap.hpp \
			DiamondTrap.hpp

SRC =		ClapTrap.cpp \
			ScavTrap.cpp \
			FragTrap.cpp \
			DiamondTrap.cpp \
			main.cpp

COMP = clang++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	$(COMP) $(CFLAGS) $(SRC) -o $(NAME) -I.