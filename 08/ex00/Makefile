NAME =		ex00

INCLUDES =	easyfind.hpp \
			easyfind.tpp

SRC =		main.cpp

COMP = clang++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	$(COMP) $(CFLAGS) $(SRC) -o $(NAME) -I.