NAME =		a.out

INCLUDES =	Fixed.hpp \
			Point.hpp \
			bsp.h

SRC =		Fixed.cpp \
			Point.cpp \
			bsp.cpp \
			main.cpp

COMP = clang++

all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	$(COMP) -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME) -I.
