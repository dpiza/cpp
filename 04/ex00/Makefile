NAME =		animals

INCLUDES =	Animal.hpp \
			Cat.hpp \
			Dog.hpp \
			WrongAnimal.hpp \
			WrongCat.hpp

SRC =		Animal.cpp \
			Cat.cpp \
			Dog.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp \
			main.cpp

COMP = clang++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	$(COMP) $(CFLAGS) $(SRC) -o $(NAME) -I.