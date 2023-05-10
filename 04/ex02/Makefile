NAME =		abstract

INCLUDES =	Animal.hpp \
			Cat.hpp \
			Dog.hpp \
			Brain.hpp 

SRC =		Animal.cpp \
			Cat.cpp \
			Dog.cpp \
			Brain.cpp \
			main.cpp

COMP = clang++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	$(COMP) $(CFLAGS) $(SRC) -o $(NAME) -I.