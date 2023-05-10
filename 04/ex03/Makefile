NAME =		interface

INCLUDES =	AMateria.hpp \
			Ice.hpp \
			Cure.hpp \
			IMateriaSource.hpp \
			MateriaSource.hpp \
			ICharacter.hpp \
			Character.hpp 

SRC =		AMateria.cpp \
			Ice.cpp \
			Cure.cpp \
			MateriaSource.cpp \
			Character.cpp \
			main.cpp

COMP = clang++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	$(COMP) $(CFLAGS) $(SRC) -o $(NAME) -I.