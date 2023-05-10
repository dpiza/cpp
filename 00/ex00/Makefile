NAME =	megaphone

SRC =		Megaphone.cpp \
			main.cpp

all: $(NAME)

$(NAME): $(SRC) Megaphone.hpp
	c++ -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME) -I.

fclean: clean

clean:
	@rm -f megaphone

